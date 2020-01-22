#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 300005
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
	x*=sign;
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
	x*=sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

struct edge {
	int from;
	int to;
	int next;
} E[maxn<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

struct left_tree {
	int l[maxn],r[maxn];
	int root[maxn];
	int dis[maxn];
	long long val[maxn];
	long long atag[maxn];
	long long mtag[maxn];
	void add_tag(int x,long long addv,long long mulv) {
		if(x==0) return;
		val[x]=(val[x]*mulv)+addv;
		mtag[x]=mtag[x]*mulv;
		atag[x]=(atag[x]*mulv)+addv;
	}
	void push_down(int x) {
		add_tag(l[x],atag[x],mtag[x]);
		add_tag(r[x],atag[x],mtag[x]);
		atag[x]=0;
		mtag[x]=1;
	}
	int _merge(int x,int y) {
		if(!x||!y) return x+y;
		push_down(x);
		push_down(y);
		if(val[x]>val[y]) swap(x,y);
		r[x]=_merge(r[x],y);
		if(dis[l[x]]<dis[r[x]]) swap(l[x],r[x]);
		dis[x]=dis[r[x]]+1;
		return x;
	}
	void merge(int x,int y) {
		root[x]=_merge(root[x],root[y]);
	}
	void insert(int x,long long v){
		val[x]=v;
		atag[x]=0;
		mtag[x]=1;
	}
	void del(int &x) {
		push_down(x);
		x=_merge(l[x],r[x]);
	}
} T;

int n,m;
long long h[maxn];
long long v[maxn];
int town[maxn],man[maxn];
int deep[maxn];
int is_mul[maxn];
int	start[maxn];
void dfs(int x,int fa) {
//	printf("%d\n",x);
	deep[x]=deep[fa]+1;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			dfs(y,x);
			T.merge(x,y);
		}
	}
	while(T.root[x]&&T.val[T.root[x]]<h[x]) {
		town[x]++;
		man[T.root[x]]=deep[start[T.root[x]]]-deep[x];
		T.del(T.root[x]);
	}
	if(is_mul[x]) {
		T.add_tag(T.root[x],0,v[x]);
	} else {
		T.add_tag(T.root[x],v[x],1);
	}
}

int main() {
	qread(n);
	qread(m);
	for(int i=1; i<=n; i++) {
		qread(h[i]);
	}
	int fa,s,c;
	for(int i=2; i<=n; i++) {
		qread(fa);
		qread(is_mul[i]);
		qread(v[i]);
		add_edge(fa,i);
		add_edge(i,fa);
	}
	for(int i=1;i<=m;i++){
		qread(s);
		qread(c);
		start[i]=c;
		T.insert(i,s);
		T.root[c]=T._merge(T.root[c],i);
	}
	dfs(1,0);
	while(T.root[1]){
		man[T.root[1]]=deep[start[T.root[1]]];
		T.del(T.root[1]);
	}
	for(int i=1; i<=n; i++) {
		qprint(town[i]);
		putchar('\n');
	}
	for(int i=1; i<=m; i++) {
		qprint(man[i]);
		putchar('\n');
	}
}
