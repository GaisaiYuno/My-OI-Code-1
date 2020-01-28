#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005 
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;	
}E[maxn<<1];
int a[maxn],b[maxn];
int size=0;
int head[maxn];
int root[maxn];
int ans[maxn];
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

struct node{
	int l;
	int r;
	int v;
}tree[maxn<<1];
int lson[maxn],rson[maxn];
void push_up(int pos){
	tree[pos].v=tree[lson[pos]].v+tree[rson[pos]].v;
}
int seg;
void build(int l,int r,int pos,int &root){
	root=++seg;
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[root].v=1;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) build(l,mid,pos,lson[pos]);
	else build(mid+1,r,pos,rson[pos]);
	push_up(pos);
}
int query(int pos,int L,int R){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(lson[pos],L,R);
	if(R>mid) ans+=query(rson[pos],L,R);
	return ans;
}

int merge(int x,int y){
	if(x==0) return y;
	if(y==0) return x;
	lson[x]=merge(lson[x],rson[y]);
	rson[x]=merge(rson[x],rson[y]);
	push_up(x);
	return x;
}

void dfs(int u,int fa){
	for(int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		if(v==fa) continue;
		dfs(v,u);
		root[u]=merge(root[u],root[v]);
	}
	ans[u]=query(root[u],a[u]+1,n);
}
void init(){
	size=0;
	seg=0;
	memset(tree,0,sizeof(tree));
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	memset(root,0,sizeof(root));
	memset(ans,0,sizeof(ans)); 
}
int main(){
	int u,v;
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			a[i]=lower_bound(b+1,b+1+n,a[i])-b;
		}
		for(int i=2;i<=n;i++){
			scanf("%d",&u);
			add_edge(u,i);
			add_edge(i,u);
		}
		for(int i=1;i<=n;i++){
			build(1,n,a[i],root[i]);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	}
}

