#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
#define maxv 52
#define mod 998244353 
using namespace std;
inline int qread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
inline void dprint(long long x) {
	if(!x) return;
    dprint(x/10);
	putchar(x%10+'0');
}
inline void qprint(long long x) {
	if(x==0) putchar('0');
	else {
		dprint(x);
	}
	putchar('\n');
}

int n,m;
struct edge {
	int from;
	int to;
	int next;
} E[maxn<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v) {
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int deep[maxn];
int fa[maxn];
int son[maxn];
int sz[maxn];
int top[maxn];
int dfn[maxn];
void dfs1(int x,int f) {
	sz[x]=1;
	fa[x]=f;
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

int cnt=0;
void dfs2(int x,int tp) {
	top[x]=tp;
	dfn[x]=++cnt;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=son[x]&&y!=fa[x]) {
			dfs2(y,y);
		}
	}
}

struct BIT {
	long long sum[maxn];
	inline int lowbit(int x) {
		return x&(-x);
	}
	inline void update(int x,int v) {
		while(x<=n) {
			sum[x]=(sum[x]+v)%mod;
			x+=lowbit(x);
		}
	}
	inline long long query_pre(int x) {
		long long ans=0;
		while(x>0) {
			ans=(ans+sum[x])%mod;
			x-=lowbit(x);
		}
		return ans;
	}
	inline long long query(int l,int r) {
		return (query_pre(r)-query_pre(l-1)+mod)%mod;
	}
} T[maxv];

long long get_sum(int x,int y,int k) {
	int tx=top[x];
	int ty=top[y];
	long long ans=0;
	while(tx!=ty) {
		if(deep[tx]<deep[ty]) {
			swap(tx,ty);
			swap(x,y);
		}
		ans+=T[k].query(dfn[tx],dfn[x]);
		ans%=mod;
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=T[k].query(dfn[x],dfn[y]);
	ans%=mod;
	return ans;
}


int main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int u,v,k;
	n=qread();
	for(int i=1; i<n; i++) {
		u=qread();
		v=qread();
		add_edge(u,v);
		add_edge(v,u);
	}
	deep[0]=-1;
	dfs1(1,0);
	dfs2(1,1);
	long long tmp;
	for(int i=1; i<=50; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1) T[i].update(dfn[j],deep[j]);
			else{
				tmp=T[i-1].query(dfn[j],dfn[j]);
				T[i].update(dfn[j],tmp*deep[j]%mod);
			}
		}
	}
	m=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		k=qread();
		qprint(get_sum(u,v,k));
	}
	return 0;
}
