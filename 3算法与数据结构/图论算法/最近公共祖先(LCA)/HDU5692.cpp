#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define INF 0x7fffffff
#define LINF 0x7fffffffffffff
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int t,n,m;
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

int cnt=0;
long long val[maxn],sum[maxn];
int lbound[maxn],pos[maxn];
int dfs1(int x,int fa) {
	lbound[x]=INF;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			lbound[x]=min(lbound[x],dfs1(y,x));
//			printf("%d %d %d\n",x,y,dfs(y,x));
		}
	}
	pos[x]=++cnt;
	if(lbound[x]==INF) lbound[x]=pos[x];
	return lbound[x];
}
void dfs2(int x,int fa){
	if(x==0) sum[pos[x]]=val[x];
	else sum[pos[x]]=val[x]+sum[pos[fa]];
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			dfs2(y,x);
		}
	}
}
struct node {
	int l;
	int r;
	long long mark;
	int is_mark;
	long long v;
} tree[maxn<<2];
void push_up(int pos) {
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	tree[pos].mark=0;
	tree[pos].is_mark=0;
	if(l==r) {
		tree[pos].v=sum[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos) {
	if(tree[pos].is_mark) {
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1].v+=tree[pos].mark;
		tree[pos<<1].is_mark=1;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1|1].v+=tree[pos].mark;
		tree[pos<<1|1].is_mark=1;
		tree[pos].mark=0;
		tree[pos].is_mark=0;
	}
}
void update(int L,int R,long long v,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		tree[pos].mark+=v;
		tree[pos].is_mark=1;
		tree[pos].v+=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}
long long query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	long long ans=-LINF;
	if(L<=mid) ans=max(ans,query(L,R,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
	return ans;
}
void ini() {
	size=0;
	cnt=0;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	memset(val,0,sizeof(val));
	memset(sum,0,sizeof(sum));
	memset(lbound,0,sizeof(lbound));
	memset(pos,0,sizeof(pos));
}
int main() {
	int u,v,cmd;
	scanf("%d",&t);
	for(int cas=1; cas<=t; cas++) {
		ini();
		scanf("%d %d",&n,&m);
		for(int i=1; i<n; i++) {
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		for(int i=0; i<n; i++) scanf("%lld",&val[i]);
		dfs1(0,-1); 
		dfs2(0,-1);
		build(1,n,1);
		printf("Case #%d:\n",cas);
		for(int i=1; i<=m; i++) {
			scanf("%d",&cmd);
			if(cmd==0) {
				scanf("%d %d",&u,&v);
				update(lbound[u],pos[u],(long long)(v-val[u]),1);
				val[u]=v;
			} else {
				scanf("%d",&u);
				printf("%lld\n",query(lbound[u],pos[u],1));
			}
		}
	}

}
