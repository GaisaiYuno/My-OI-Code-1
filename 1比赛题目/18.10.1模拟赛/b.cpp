//For my love Selina
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxm 100005
#define maxn 50005
#define INF 10000000005
#define maxlog 32
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int next;
	edge() {

	}
	edge(int u,int v,int h) {
		from=u;
		to=v;
		next=h;
	}
};
edge E[maxm*2];
int siz;
int head[maxn];
void add_edge(int u,int v) {
	siz++;
	E[siz].from=u;
	E[siz].to=v;
	E[siz].next=head[u];
	head[u]=siz;
}


struct node {
	int l;
	int r;
	long long v;
	long long mark;
	int len() {
		return r-l+1;
	}
} tree[maxn<<2];
void push_up(int pos) {
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=INF;
	tree[pos].mark=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void push_down(int pos) {
	if(tree[pos].mark) {
		if(tree[pos<<1].v!=0) tree[pos<<1].v=min(tree[pos<<1].v,tree[pos].mark);
		else tree[pos<<1].v=tree[pos].mark;
		if(tree[pos<<1|1].v!=0)tree[pos<<1|1].v=min(tree[pos<<1|1].v,tree[pos].mark);
		else tree[pos<<1|1].v=tree[pos].mark;
		if(tree[pos<<1].mark!=0) tree[pos<<1].mark=min(tree[pos<<1].mark,tree[pos].mark);
		else tree[pos<<1].mark=tree[pos].mark;
		if(tree[pos<<1|1].mark!=0) tree[pos<<1|1].mark=min(tree[pos<<1|1].mark,tree[pos].mark);
		else tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void update(int L,int R,long long v,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		if(tree[pos].v!=0)tree[pos].v=min(tree[pos].v,v);
		else tree[pos].v=v;
		if(tree[pos].mark!=0) tree[pos].mark=min(tree[pos].mark,v);
		else tree[pos].mark=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}

long long query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	long long ans=INF;
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) ans=min(ans,query(L,R,pos<<1));
	if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
	return ans;
}


int log2n;
int deep[maxn];
int dfn[maxn];
int top[maxn];
int fa[maxn];
int son[maxn];
int sz[maxn];
int anc[maxn][maxlog];
void dfs(int x,int father){
	deep[x]=deep[father]+1;
	fa[x]=father;
	anc[x][0]=father;
	sz[x]=1;
	son[x]=0;
	for(int i=1;i<=log2n;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=father){
			dfs(y,x);
			if(sz[y]>sz[son[x]]) son[x]=y;
			sz[x]+=sz[y];
		}
	}
}

int cnt=0;
void dfs2(int x,int tp){
	dfn[x]=++cnt;
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=son[x]&&y!=fa[x]){
			dfs2(y,y);
		}
	}
}

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
void change(int x,int y,long long v){
	int l=lca(x,y);
	long long orig=query(dfn[l],dfn[l],1);
	int tx=top[x],ty=top[y];
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		update(dfn[tx],dfn[x],v,1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	update(dfn[x],dfn[y],v,1);
	update(dfn[l],dfn[l],0,1);
	update(dfn[l],dfn[l],orig,1);
}
int main() {
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	int u,v;
	long long w;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1;
	for(int i=1; i<=n-1; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	dfs2(1,1);
	build(1,n,1);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %lld",&u,&v,&w);
		change(u,v,w);
//		printf("debug:%lld %lld %lld\n",query(dfn[u],dfn[u],1),query(dfn[v],dfn[v],1),query(dfn[lca(u,v)],dfn[lca(u,v)],1));
	}
	long long tmp;
	for(int i=1;i<=n-1;i++){
		u=E[i*2-1].from;
		v=E[i*2-1].to;
		if(deep[u]<deep[v]) swap(u,v);
		tmp=query(dfn[u],dfn[u],1);
		if(tmp<INF)printf("%lld\n",tmp);
		else printf("-1\n");
	}
}

/*
6 3
4 1
1 3
4 5
1 2
6 5
3 6 8
2 3 7
6 4 5
*/
