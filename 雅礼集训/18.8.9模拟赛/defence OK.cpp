#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;
int n,m,q;
struct edge{
	int from;
	int to;
	int next;	
}E[maxn<<1];
int head[maxn];
int size=0;
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

struct node{
	int lson;
	int rson;
	int lmax;
	int rmax;
	int maxv;
}tree[maxn*5];
int root[maxn],ans[maxn];
void push_up(int rt,int l,int r){
	int mid=(l+r)>>1;
	if(tree[rt].lson&&tree[rt].rson){
		tree[rt].lmax=tree[tree[rt].lson].lmax;
		tree[rt].rmax=tree[tree[rt].rson].rmax;
		tree[rt].maxv=max(max(tree[tree[rt].lson].maxv,tree[tree[rt].rson].maxv),tree[tree[rt].lson].rmax+tree[tree[rt].rson].lmax);
	}else if(tree[rt].lson){
		tree[rt].lmax=tree[tree[rt].lson].lmax;
		tree[rt].rmax=tree[tree[rt].lson].rmax+r-mid;
//		tree[rt].maxv=max(tree[tree[rt].lson].maxv,max(tree[rt].lmax,tree[rt].rmax));
		tree[rt].maxv=tree[tree[rt].lson].maxv;
	}else if(tree[rt].rson){
		tree[rt].lmax=tree[tree[rt].rson].lmax+mid-l+1;
		tree[rt].rmax=tree[tree[rt].rson].rmax;
//		tree[rt].maxv=max(tree[tree[rt].rson].maxv,max(tree[rt].lmax,tree[rt].rmax));
		tree[rt].maxv=tree[tree[rt].rson].maxv;
	}
}
int cnt=0;
inline void update(int &rt,int x,int l,int r){
	if(!rt) rt=++cnt;
	if(l==r){
		tree[rt].lmax=tree[rt].rmax=tree[rt].maxv=0;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(tree[rt].lson,x,l,mid);
	else update(tree[rt].rson,x,mid+1,r);
	push_up(rt,l,r);
}
inline int merge(int x,int y,int l,int r){
	if(x==0||y==0) return x|y;
	int mid=(l+r)>>1;
	tree[x].lson=merge(tree[x].lson,tree[y].lson,l,mid);
	tree[x].rson=merge(tree[x].rson,tree[y].rson,mid+1,r);
	push_up(x,l,r);
	return x;
}
vector<int>magic[maxn];
inline void dfs(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y==fa) continue;
		dfs(y,x);
		root[x]=merge(root[x],root[y],1,m);
	}
	int sz=magic[x].size();
	for(int i=0;i<sz;i++) update(root[x],magic[x][i],1,m);
	if(!root[x]) ans[x]=-1;
	else ans[x]=max(tree[root[x]].maxv,tree[root[x]].lmax+tree[root[x]].rmax);
}

int main(){
//	freopen("defence2.in","r",stdin);
	scanf("%d %d %d",&n,&m,&q);
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		magic[u].push_back(v); 
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++) printf("%d ",root[i]);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
