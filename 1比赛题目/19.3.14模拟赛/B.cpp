#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define maxn 300005
#define INF 0x3f3f3f3f
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
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,m;
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

struct node {
	long long power;
	long long id;
	node(long long p,int i) {
		power=p;
		id=i;
	}
	friend bool operator < (node p,node q) {
		if(p.power==q.power) return p.id<q.id;
		else return p.power<q.power;
	}
};
int h[maxn];
int v[maxn];
int a[maxn];
int s[maxn];
int c[maxn];
multiset<node>f[maxn];

int deep[maxn];
int kg_cnt[maxn],city_cnt[maxn];
void merge(int x,int y) {
	if(f[x].size()<f[y].size()) swap(f[x],f[y]);
	for(auto k : f[y]) {
		f[x].insert(k);
	}
}

multiset<node>tmp;
void dfs(int x,int fa) {
//	printf("db:%d %d\n",x,fa);
	deep[x]=deep[fa]+1;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			dfs(y,x);
			merge(x,y);
		}
	}
//	printf("set:\n");
//	for(auto p : f[x]){
//		printf("(val=%lld id=%d)\t",p.power,p.id);
//	}
//	printf("\n");
	auto pos=f[x].upper_bound(node(INF,h[x]-1));
	if(pos!=f[x].begin()) {
		pos--;
		for(auto it=f[x].begin(); it!=pos; it++) {
			city_cnt[x]++;
			kg_cnt[x]=deep[c[it->id]]-deep[x];
		}
		f[x].erase(f[x].begin(),pos);
	}
	tmp.clear();
	for(auto it=f[x].begin(); it!=f[x].end(); it++) {
		node val=*it;
//		f[x].erase(it);
		val.power=val.power*v[x]+a[x];
		tmp.insert(val);
	}
	f[x].clear();
	for(auto p : tmp){
		f[x].insert(p);
	}
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=2;i<=n;i++){
		int fa,flag,val;
		scanf("%d %d %d",&fa,&flag,&val);
		if(flag==0){
			a[i]=val;
			v[i]=1;
		}else{
			a[i]=0;
			v[i]=val;
		}
		add_edge(fa,i);
		add_edge(i,fa);
	}
	for(int i=1;i<=n;i++){
		scanf("%d %d",&s[i],&c[i]);
	}
	for(int i=1;i<=n;i++){
		f[c[i]].insert(node(s[i],i));
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%d\n",city_cnt[i]);
	}
//	printf("\n");
	for(int i=1;i<=m;i++){
		printf("%d\n",kg_cnt[i]);
	}
}
