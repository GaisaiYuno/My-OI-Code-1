#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200000
#define mod 998244353
using namespace std;
typedef long long ll;
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
inline void qprint(ll x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

inline ll fast_pow(ll x,ll k) {
	ll ans=1;
	while(k) {
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

int n,m,k;
struct edge {
	int from;
	int to;
	int next;
} E[maxn*2+5];
int esz=1;
int head[maxn+5];
void add_edge(int u,int v) {
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}


int deep[maxn+5],sz[maxn+5],fa[maxn+5],son[maxn+5],top[maxn+5],dfn[maxn+5],hash_dfn[maxn+5];
void dfs1(int x,int f) {
	fa[x]=f;
	sz[x]=1;
	deep[x]=deep[f]+1;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=f) {
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[son[x]]<sz[y]) son[x]=y;
		}
	}
}
int tim;
void dfs2(int x,int t) {
	dfn[x]=++tim;
	hash_dfn[dfn[x]]=x;
	top[x]=t;
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





struct query {
	int x;
	int y;
	ll ans;
	friend bool operator < (query p,query q) {
		return p.x<q.x;
	}
} q[maxn+5];
vector<int>id[maxn+5];
ll val[maxn+5];//预处理每个点的贡献
struct segment_tree {
	struct node {
		int l;
		int r;
		ll sum;
		ll delta;//每次计算要加上的贡献,等于sum(val[i]) (l<=i<=r) 
		ll addm;//记录每个区间的贡献被计算的次数 
		int len() {
			return r-l+1;
		}
	} tree[maxn*4+5];
	void push_up(int pos) {
		tree[pos].sum=(tree[pos<<1].sum+tree[pos<<1|1].sum)%mod;
		tree[pos].delta=(tree[pos<<1].delta+tree[pos<<1|1].delta)%mod;
	}
	void build(int l,int r,ll *a,int pos) {
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			tree[pos].delta=a[hash_dfn[l]];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,a,pos<<1);
		build(mid+1,r,a,pos<<1|1);
		push_up(pos);
	}
	void add_tag(int x,int mark) {
		tree[x].sum+=mark*tree[x].delta%mod;
		tree[x].sum%=mod;
		tree[x].addm+=mark;
		tree[x].addm%=mod;
	}
	void push_down(int x) {
		if(tree[x].addm) {
			add_tag(x<<1,tree[x].addm);
			add_tag(x<<1|1,tree[x].addm);
			tree[x].addm=0;
		}
	}
	void update(int L,int R,int val,int pos) {
		if(L<=tree[pos].l&&R>=tree[pos].r) {
			add_tag(pos,val);
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	ll query(int L,int R,int pos) {
		if(L<=tree[pos].l&&R>=tree[pos].r) {
			return tree[pos].sum;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		ll ans=0;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid) ans+=query(L,R,pos<<1|1);
		return ans;
	}
} T;

void update(int x,int y) {
	int tx=top[x],ty=top[y];
	while(tx!=ty) {
		if(deep[tx]<deep[ty]) {
			swap(x,y);
			swap(tx,ty);
		}
		T.update(dfn[tx],dfn[x],1,1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	T.update(dfn[x],dfn[y],1,1);
}
ll query(int x,int y) {
	ll ans=0;
	int tx=top[x],ty=top[y];
	while(tx!=ty) {
		if(deep[tx]<deep[ty]) {
			swap(x,y);
			swap(tx,ty);
		}
		ans+=T.query(dfn[tx],dfn[x],1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=T.query(dfn[x],dfn[y],1);
	return ans;
}


int main() {
	int f;
	qread(n);
	qread(m);
	qread(k);
	for(int i=2; i<=n; i++) {
		qread(f);
		add_edge(i,f);
		add_edge(f,i);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1; i<=m; i++) {
		qread(q[i].x);
		qread(q[i].y);
		id[q[i].x].push_back(i);
	}
	for(int i=1;i<=n;i++){
		val[i]=(fast_pow(deep[i],k)-fast_pow(deep[i]-1,k)+mod)%mod;
	}
	T.build(1,n,val,1);
	for(int i=1; i<=n; i++) {
		update(1,i);
		for(int j=0; j<(int)id[i].size(); j++) {
			int num=id[i][j];
			q[num].ans=query(1,q[num].y)%mod;
		}
	}
	for(int i=1; i<=m; i++) {
		qprint(q[i].ans);
		putchar('\n');
	}
}

/*
5 5 1
1
4
1
2
4 3
5 4
2 5
1 2
3 2
*/
