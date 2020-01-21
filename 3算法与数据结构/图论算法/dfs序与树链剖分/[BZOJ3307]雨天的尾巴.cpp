#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxlogn 60 
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
void dfs1(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs1(y,x);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=maxlogn;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=maxlogn;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

struct segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int cnt;
		int id;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		if(tree[lson(x)].cnt>tree[rson(x)].cnt){
			tree[x].cnt=tree[lson(x)].cnt;
			tree[x].id=tree[lson(x)].id;
		}else if(tree[lson(x)].cnt==tree[rson(x)].cnt){
			tree[x].cnt=tree[lson(x)].cnt;
			tree[x].id=min(tree[lson(x)].id,tree[rson(x)].id);
		}else{
			tree[x].cnt=tree[rson(x)].cnt;
			tree[x].id=tree[rson(x)].id;
		}
	}
	void update(int &x,int upos,int uval,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].cnt+=uval;
			tree[x].id=l;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,upos,uval,l,mid);
		else update(tree[x].rs,upos,uval,mid+1,r);
		push_up(x);
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y) return x+y;
		if(l==r){
			tree[x].cnt+=tree[y].cnt;
			tree[x].id=l;
			return x;
		}
		int mid=(l+r)>>1;
		tree[x].ls=merge(tree[x].ls,tree[y].ls,l,mid);
		tree[x].rs=merge(tree[x].rs,tree[y].rs,mid+1,r);
		push_up(x);
		return x; 
	}
}T;
int root[maxn+5];
int ans[maxn+5];

int maxz;
struct query{
	int x;
	int y;
	int z;
}q[maxn+5]; 
void dfs2(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x);
			root[x]=T.merge(root[x],root[y],1,maxz);
		}
	}
	if(T.tree[root[x]].cnt) ans[x]=T.tree[root[x]].id;
	else ans[x]=0;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	maxz=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].z);
		maxz=max(q[i].z,maxz);
	}
	for(int i=1;i<=m;i++){
		int x=q[i].x,y=q[i].y,z=q[i].z,lc=lca(x,y);
		T.update(root[x],z,1,1,maxz);
		T.update(root[y],z,1,1,maxz);
		T.update(root[lc],z,-1,1,maxz);
		T.update(root[anc[lc][0]],z,-1,1,maxz);
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}

 
