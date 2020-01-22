#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
#define maxv 52
#define maxlog 32
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

inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
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
int anc[maxn][maxlog];
long long sum[maxn][maxv];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=0;i<=50;i++){
		sum[x][i]=(sum[fa][i]+fast_pow(deep[x]-1,i))%mod;
//		printf("sum[%d][%d]=%d\n",x,i,sum[x][i]);
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
}

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		} 
	}
	return anc[x][0];
}

long long query(int x,int y,int k){
	int l=lca(x,y);
	long long ans=sum[x][k]+sum[y][k]-sum[l][k]-sum[anc[l][0]][k];
	while(ans<0) ans+=mod;
	return ans%mod;
}

int main(){
	int u,v,k;
	n=qread();
	for(int i=1; i<n; i++) {
		u=qread();
		v=qread();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	m=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		k=qread();
		qprint(query(u,v,k));
	}
}
