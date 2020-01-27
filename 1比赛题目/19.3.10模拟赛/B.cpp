#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
#define maxn 1000005
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qread(long long &x) {
	x=0;
	long long sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,m;
long long a[maxn];

struct edge {
	int from;
	int to;
	int next;
} E[maxn<<1];
int head[maxn];
int esz=1;
void add_edge(int u,int v) {
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}
int cnt=0;
int deep[maxn],dfn[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],hs[maxn];
void dfs1(int x,int f) {
	deep[x]=deep[f]+1;
	fa[x]=f;
	sz[x]=1;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=f) {
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}
void dfs2(int x,int tp){
	dfn[x]=++cnt;
	hs[dfn[x]]=x;
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
} 

struct segment_tree {
	struct node {
		int l;
		int r;
		long long v;
		long long mark;
		long long len() {
			return r-l+1;
		}
	} tree[maxn<<2];
	void push_up(int pos) {
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos) {
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) {
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void build(int l,int r,int pos,long long *a) {
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) {
			tree[pos].v=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1,a);
		build(mid+1,r,pos<<1|1,a);
		push_up(pos);
	}
	void push_down(int pos) {
		if(tree[pos].mark) {
			tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
			tree[pos<<1].mark+=tree[pos].mark;
			tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len();
			tree[pos<<1|1].mark+=tree[pos].mark;
			tree[pos].mark=0;
		}
	}
	void update(int L,int R,long long v,int pos) {
		if(L<=tree[pos].l&&R>=tree[pos].r) {
			tree[pos].v+=v*tree[pos].len();
			tree[pos].mark+=v;
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
		long long ans=0;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid) ans+=query(L,R,pos<<1|1);
		return ans;
	}
	void output(long long *out,int pos){
		if(tree[pos].l==tree[pos].r){
			out[hs[tree[pos].l]]=tree[pos].v;
			return;
		}
		push_down(pos);
		output(out,pos<<1);
		output(out,pos<<1|1);
	} 
}T1,T2;

void upd_route(int x,int y,long long v){
	int tx=top[x];
	int ty=top[y];
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		T1.update(dfn[x],dfn[tx],v,1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	T1.update(dfn[x],dfn[y],v,1);
}
long long tmp[maxn];
void change(int u,long long v){
	long long pre=T1.query(dfn[u],dfn[u],1);
	long long delta=v-pre;
	upd_route(u,1,delta);
	for(int i=1;i<=n;i++){
		tmp[i]=T1.query(dfn[i],dfn[i]+sz[i]-1,1);
	}
	T2.build(1,n,1,tmp);
}
long long ask(int l,int r){
	return T2.query(l,r,1);
}
int main() {
	int op,u,v,l,r,root;
	long long k;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	for(int i=1;i<=n;i++){
		qread(u);
		qread(v);
		if(u==0) root=v;
		else{
			add_edge(u,v);
			add_edge(v,u);
		}
	}
	dfs1(root,0);
	dfs2(root,root);
	T1.build(1,n,1); 
	for(int i=1;i<=n;i++){
		T1.update(dfn[i],dfn[i],a[i],1);
	}
	for(int i=1;i<=n;i++){
		tmp[i]=T1.query(dfn[i],dfn[i]+sz[i]-1,1);
	}
	T2.build(1,n,1,tmp);
	for(int i=1;i<=m;i++){
		qread(op);
		if(op==1){
			qread(u);
			qread(k);
			change(u,k);
		}else{
			qread(l);
			qread(r);
			qprint(ask(l,r));
			putchar('\n');
		}
	}
}

