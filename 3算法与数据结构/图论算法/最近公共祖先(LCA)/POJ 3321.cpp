#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define INF 0x7fffffff
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int next;
} E[maxn*2];
int head[maxn];
int size=0;
void add_edge(int u,int v) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int root=1;
int cnt=0;
int lbound[maxn],pos[maxn];
int dfs(int x,int fa) {
	lbound[x]=INF;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			lbound[x]=min(lbound[x],dfs(y,x));
//			printf("%d %d %d\n",x,y,dfs(y,x));
		}
	}
	pos[x]=++cnt;
	if(lbound[x]==INF) lbound[x]=pos[x];
	return lbound[x];
}

struct node {
	int l;
	int r;
	int v;
} tree[maxn<<2];
void push_up(int pos) {
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	if(l==r) {
		tree[pos].v=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void update(int tpos,int v,int pos) {
	if(tree[pos].l==tree[pos].r) {
		tree[pos].v=1-tree[pos].v;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(tpos<=mid) update(tpos,v,pos<<1);
	else update(tpos,v,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].v;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(L,R,pos<<1);
	if(R>mid) ans+=query(L,R,pos<<1|1);
	return ans;
}
int main() {
	int u,v;
	scanf("%d",&n);
	for(int i=1; i<=n-1; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	scanf("%d",&m);
	char cmd;
	build(1,n,1);
	for(int i=1; i<=m; i++) {
		cin>>cmd;
		scanf("%d",&u);
		if(cmd=='C'){
			update(pos[u],1,1);
		}else{
			printf("%d\n",query(lbound[u],pos[u],1)); 
		}
	}
}
