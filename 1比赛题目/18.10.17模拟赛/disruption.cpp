#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxlog 32
#define maxn 500005
#define INF 0x7f7f7f7f7f7f7f
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

inline void dprint(long long x){
	if(x==0) return;
	dprint(x/10);
	putchar(x%10+'0');
}

inline void qprint(long long x){
	if(x==0) putchar('0');
	else if(x<0){
		putchar('-');
		dprint(-x);
	}else{
		dprint(x);
	}
	putchar('\n');
}

int n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int ptr=0;
int head[maxn];
void add_edge(int u,int v){
	ptr++;
	E[ptr].from=u;
	E[ptr].to=v;
	E[ptr].next=head[u];
	head[u]=ptr;
}

int log2n;
int cnt;
int deep[maxn];
int fa[maxn];
int son[maxn];
int sz[maxn];
int dfn[maxn];
int top[maxn];
int anc[maxn][maxlog];
void dfs1(int x,int f){
	deep[x]=deep[f]+1;
	sz[x]=1;
	anc[x][0]=f;
	fa[x]=f;
	for(int i=1;i<=log2n;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}

void dfs2(int x,int tp){
	dfn[x]=++cnt;
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
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

struct node{
	int l;
	int r;
	long long v;
	long long mark;
	int len(){
		return r-l+1;
	}
}tree[maxn<<2];

void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}

void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=INF;
	if(l==r) return;
	int mid=(l+r)>>1; 
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}

void push_down(int pos){
	if(tree[pos].mark!=0){
		if(tree[pos<<1].mark==0||tree[pos<<1].mark>tree[pos].mark) tree[pos<<1].mark=tree[pos].mark;
		if(tree[pos<<1].v==0||tree[pos<<1].v>tree[pos].mark) tree[pos<<1].v=tree[pos].mark;
		if(tree[pos<<1|1].mark==0||tree[pos<<1|1].mark>tree[pos].mark) tree[pos<<1|1].mark=tree[pos].mark;
		if(tree[pos<<1|1].v==0||tree[pos<<1|1].v>tree[pos].mark) tree[pos<<1|1].v=tree[pos].mark;
		tree[pos].mark=0;
	}
}

void update(int L,int R,long long v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		if(tree[pos].v==0||tree[pos].v>v){
			tree[pos].v=v;
			tree[pos].mark=v;
			return;
		}else return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
} 

long long query(int tpos,int pos){
	if(tree[pos].l==tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(tpos<=mid) return query(tpos,pos<<1);
	else return query(tpos,pos<<1|1); 
}


void change(int x,int y,long long v){
	int tx=top[x];
	int ty=top[y];
	int l=lca(x,y);
	long long tv=query(dfn[l],1);
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
	update(dfn[l],dfn[l],tv,1);
}

int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	int u,v;
	long long w;
	n=qread();
	m=qread();
	log2n=log2(n)+1;
	for(int i=2;i<=n;i++){
		u=qread();
		v=qread();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		w=qread();
		change(u,v,w);
	}
	long long ans;
//	for(int i=1;i<=n;i++){
//		printf("%d ",query(dfn[i],1));
//	}
//	printf("\n");
	for(int i=1;i<=ptr;i+=2){
		u=E[i].from;
		v=E[i].to;
		if(deep[u]>deep[v]) swap(u,v);
		ans=query(dfn[v],1);
		if(ans==INF) ans=-1;
		qprint(ans); 
	}
}
