#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxlogn 50
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5]; 
int esz=0;
int head[maxn+5];
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}

int sz[maxn+5],deep[maxn+5],son[maxn+5],top[maxn+5],dfn[maxn+5],fa[maxn+5];
void dfs1(int x,int father){
	sz[x]=1;
	son[x]=0;
	fa[x]=father;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=father){
			deep[y]=deep[x]+1;
			dfs1(y,x);
			sz[x]+=sz[y];
			if(!son[x]||sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}
int cnt=0;
void dfs2(int x,int to){
	dfn[x]=++cnt;
	top[x]=to;
	if(son[x]) dfs2(son[x],to);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
}

struct segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int cnt;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].cnt=tree[lson(x)].cnt+tree[rson(x)].cnt;
	}
	void update(int &x,int upos,int uval,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].cnt+=uval;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(lson(x),upos,uval,l,mid);
		else update(rson(x),upos,uval,mid+1,r);
		push_up(x);
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r){
			return tree[x].cnt;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(lson(x),L,R,l,mid);
		if(R>mid) ans+=query(rson(x),L,R,mid+1,r);
		return ans; 
	}
}T;
int root[maxn+5];
int query(int x,int y,int color){
	int tx=top[x],ty=top[y];
	int ans=0;
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		ans+=T.query(root[color],dfn[tx],dfn[x],1,n);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=T.query(root[color],dfn[x],dfn[y],1,n);
	return ans; 
}

int c[maxn+5];
int ans[maxn+5];
int main(){
#ifndef LOCAL
	freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
#endif
	int u,v;
	int x,y,z;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		T.update(root[c[i]],dfn[i],1,1,n);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&z);
		if(query(x,y,z)>0) ans[i]=1;
		else ans[i]=0;
	}
	for(int i=1;i<=m;i++) printf("%d",ans[i]);
}
