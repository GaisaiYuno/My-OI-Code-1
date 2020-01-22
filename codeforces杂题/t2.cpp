#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200000
#define maxm 200000
#define maxlogn 22
using namespace std;
int t,n,m;
struct edge {
	int from;
	int to;
	int next;
} E[maxn*2+5];
int head[maxn+5];
int esz=1;
void add_edge(int u,int v) {
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}


int dn;
int a[maxn+5];
int tmp[maxn+5];
void discrete(int *a,int &sz) {
	for(int i=1; i<=n; i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	sz=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1; i<=n; i++) a[i]=lower_bound(tmp+1,tmp+1+sz,a[i])-tmp;
}
struct route {
	int x;
	int y;
	int k;
	int lc;
	long long w;
} q[maxm+5];

int tim;
int sz[maxn+5],deep[maxn+5],hash_dfn[maxn+5],dfn[maxn+5],top[maxn+5],son[maxn+5],fa[maxn+5];
void dfs1(int x,int f) {
	fa[x]=f;
	sz[x]=1;
	deep[x]=deep[f]+1;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=f) {
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}
void dfs2(int x,int t) {
	top[x]=t;
	dfn[x]=++tim;
	hash_dfn[dfn[x]]=x;
	if(son[x]) dfs2(son[x],t);
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]) {
			dfs2(y,y);
		}
	}
}
int lca(int x,int y) {
	while(top[x]!=top[y]) {
		if(deep[top[x]]>deep[top[y]]) x=fa[top[x]];
		else y=fa[top[y]];
	}
	if(deep[x]<deep[y]) return x;
	else return y;
}


struct persist_segment_tree {//主席树 
	struct node {
		int ls;
		int rs;
		int cnt;
	} tree[maxn*maxlogn];
	int root[maxn];
	int ptr;
	void push_up(int x) {
		tree[x].cnt=tree[tree[x].ls].cnt+tree[tree[x].rs].cnt;
	}
	void update(int &x,int last,int upos,int l,int r) {
		x=++ptr;
		tree[x]=tree[last];
		if(l==r) {
			tree[x].cnt++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
		else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
		push_up(x);
	}
	int query(int x,int y,int lc,int lcfa,int k,int l,int r) {
		if(l==r) return l;
		int mid=(l+r)>>1;
		int lcnt=tree[tree[x].ls].cnt+tree[tree[y].ls].cnt-tree[tree[lc].ls].cnt-tree[tree[lcfa].ls].cnt;
		if(k<=lcnt) return query(tree[x].ls,tree[y].ls,tree[lc].ls,tree[lcfa].ls,k,l,mid);
		else return query(tree[x].rs,tree[y].rs,tree[lc].rs,tree[lcfa].rs,k-lcnt,mid+1,r);
	}
}T;
int root[maxn+5];
int calc(route p){//查询路径第k大 
	int x=p.x,y=p.y,lc=p.lc,lcfa=fa[lc],k=p.k;
	int pos=T.query(root[dfn[x]],root[dfn[y]],root[dfn[lc]],root[dfn[lcfa]],k,1,dn);
	return tmp[pos];
}

struct segment_tree {//普通线段树 
	struct node {
		int l;
		int r;
		long long sum;
	} tree[maxn*4+5];
	void push_up(int pos) {
		tree[pos].sum=tree[pos<<1].sum+tree[pos<<1|1].sum;
	}
	void build(int l,int r,int pos) {
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].sum=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void update(int upos,long long uval,int pos) {
		if(tree[pos].l==tree[pos].r) {
			tree[pos].sum+=uval;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update(upos,uval,pos<<1);
		else update(upos,uval,pos<<1|1);
		push_up(pos);
	}
	long long query(int L,int R,int pos) {
		if(L<=tree[pos].l&&R>=tree[pos].r) {
			return tree[pos].sum;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		long long ans=0;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid) ans+=query(L,R,pos<<1|1);
		return ans;
	}
} T1,T2; //T1维护sum,T2维护dp


void update_point(int x,long long uval,segment_tree &T) {
	T.update(dfn[x],uval,1);
}
long long query_route(int x,int y,segment_tree &T) {
	int tx=top[x];
	int ty=top[y];
	long long ans=0;
	while(tx!=ty) {
		if(deep[tx]<deep[ty]) {
			swap(tx,ty);
			swap(x,y);
		}
		ans+=T.query(dfn[tx],dfn[x],1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=T.query(dfn[x],dfn[y],1);
	return ans;
}


vector<int>rid[maxn+5];//两端点lca为x的链的编号
long long sum[maxn+5];//sum(dp[son(x)])
long long dp[maxn+5];
void dfs3(int x) { //dp过程
	sum[x]=0;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa[x]) {
			dfs3(y);
			sum[x]+=dp[y];
		}
	}
	dp[x]=sum[x];
	update_point(x,sum[x],T1);//因为下一步就要用到，这里要更新sum[x]
	for(int i=0; i<(int)rid[x].size(); i++) {
		int k=rid[x][i];
		dp[x]=max(dp[x],q[k].w+query_route(q[k].x,q[k].y,T1)-query_route(q[k].x,q[k].y,T2));
	}
	update_point(x,dp[x],T2);
}


int main() {
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1; i<n; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=m;i++) scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].k);
	
	discrete(a,dn);
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		int x=hash_dfn[i],f=fa[x];
		T.update(root[dfn[x]],root[dfn[f]],a[x],1,dn);
	}
	
	for(int i=1; i<=m; i++) {
		q[i].lc=lca(q[i].x,q[i].y);
		rid[q[i].lc].push_back(i);
		q[i].w=calc(q[i]);
	}
	T1.build(1,n,1);
	T2.build(1,n,1); 
	dfs3(1);
	printf("%lld\n",dp[1]);


}

