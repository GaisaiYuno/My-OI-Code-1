## [51nod 1766]树上的最远点对 (树的直径+ST表求lca+线段树)

### 题面

给出一棵N个点的树，Q次询问一点编号在区间[l1,r1]内，另一点编号在区间[l2,r2]内的所有点对距离最大值。$N, Q≤100000$

### 分析

看到区间，我们应该想到用线段树维护，区间[l,r]存储编号在[l,r]内的点组成的一棵树的直径端点和长度

考虑如何合并区间。设两个区间的直径分别为(a,b) (c,d),则新区间的直径端点肯定也是a,b,c,d中的一个。（证明显然）,那么新区间的直径就是max(dist(a,b),dist(a,c),dist(a,d),dist(b,c),dist(b,d),dist(c,d))

那么直接线段树维护就行了，pushup的时候按上面的那样合并。最后查询得到[l1,r1]内的直径(a,b),[l2,r2]内的直径(c,d) ,答案就是max(dist(a,c),dist(b,d),dist(b,c),dist(a,d))

如果用树上倍增求lca，时间复杂度为$O(n\log^2n)$,改用dfs序+ST表求lca，查询只需要在ST表中求最值，是O(1)的，时间复杂度$O(n\log n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxlogn 25
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
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar(x%10+'0');
	}
}

int n,m;
struct edge {
	int from;
	int to;
	int next;
	int len;
} E[maxn*2+5];
int head[maxn+5];
int esz=1;
void add_edge(int u,int v,int w) {
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].len=w;
	E[esz].next=head[u];
	head[u]=esz;
}

int cnt=0;
long long dis[maxn+5];
int seq[maxn*2+5];
int first[maxn+5];
int deep[maxn*2+5];
void dfs(int x,int fa,int d) {
	seq[++cnt]=x;
	deep[cnt]=d;
	first[x]=cnt;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			dis[y]=dis[x]+E[i].len;
			dfs(y,x,d+1);
			seq[++cnt]=x;
			deep[cnt]=d;
		}
	}
}

struct ST {//ST表求lca
	int log2[maxn*2+5];
	int f[maxn*2+5][maxlogn+5];
	void ini(int n) {
		log2[0]=-1;
		for(int i=1; i<=n; i++) log2[i]=log2[i>>1]+1;
		for(int i=1; i<=n; i++) f[i][0]=i;
		for(int j=1; (1<<j)<=n; j++) {
			for(int i=1; i+(1<<j)-1<=n; i++) {
				int x=f[i][j-1];
				int y=f[i+(1<<(j-1))][j-1];
				if(deep[x]<deep[y]) f[i][j]=x;
				else f[i][j]=y;
			}
		}
	}
	int query(int l,int r) {
		int k=log2[r-l+1];
		int x=f[l][k];
		int y=f[r-(1<<k)+1][k];
		if(deep[x]<deep[y]) return x;
		else return y;
	}
} S;
inline int lca(int x,int y) {
	x=first[x];
	y=first[y];
	if(x>y) swap(x,y);
	return seq[S.query(x,y)];
}
inline long long dist(int x,int y) {
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}


struct value {//直径的端点与长度
	int u;
	int v;
	long long dis;
	value() {

	}
	value(int _u,int _v,int _dis) {
		u=_u;
		v=_v;
		dis=_dis;
	}
	inline void cal(int x,int y) {
		long long len=dist(x,y);
		if(len>dis) {
			dis=len;
			u=x;
			v=y;
		}
	}
	friend value operator + (value p,value q) {//合并答案
		if(p.u==0) return q;//注意一个为空的情况
		if(q.u==0) return p;
		int a=p.u,b=p.v,c=q.u,d=q.v;
		value ans=value(0,0,0);
		ans.cal(a,b);
		ans.cal(a,c);
		ans.cal(a,d);
		ans.cal(b,c);
		ans.cal(b,d);
		ans.cal(c,d);
		return ans;
	}
};

struct segment_tree {
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
	struct node {
		int l;
		int r;
		value val;
	} tree[maxn*4+5];
	void push_up(int x) {
		tree[x].val=tree[lson(x)].val+tree[rson(x)].val;//重载之后运算变得很简洁
	}
	void build(int l,int r,int pos) {
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].val=value(0,0,0);
		if(l==r) {
			tree[pos].val=value(l,l,0);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	value query(int L,int R,int pos) {
		if(L<=tree[pos].l&&R>=tree[pos].r) {
			return tree[pos].val;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		value ans=value(0,0,0);
		if(L<=mid) ans=ans+query(L,R,pos<<1);
		if(R>mid) ans=ans+query(L,R,pos<<1|1);
		return ans;
	}
} T;


int main() {
	int u,v,w;
	int l1,r1,l2,r2;
	qread(n);
	for(int i=1; i<n; i++) {
		qread(u);
		qread(v);
		qread(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs(1,0,1);
	S.ini(cnt);
	T.build(1,n,1);
	
	qread(m);
	for(int i=1; i<=m; i++) {
		qread(l1);
		qread(r1);
		qread(l2);
		qread(r2);
		value ans1=T.query(l1,r1,1);
		value ans2=T.query(l2,r2,1);
		//ans=ans1+ans2 
		int a=ans1.u,b=ans1.v,c=ans2.u,d=ans2.v;//这里不能只选ans1或ans2,所以不能写ans1+ans2 
		qprint(max(max(dist(a,c),dist(b,d)),max(dist(a,d),dist(b,c))));
		putchar('\n');
	}
}

```



