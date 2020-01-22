#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
#define maxm 2005
#define mod 1000000007
using namespace std;
int n,m;
long long V;
inline long long fact(long long x){
	long long ans=1;
	for(long long i=2;i<=x;i++){
		ans=(ans*i)%mod;
	}
	return ans;
}
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		k>>=1;
	}
	return ans;
}
inline long long inv(long long x){
	return fast_pow(x,mod-2)%mod;
}
inline long long C(int a,int b){
	return (fact(a)*inv(fact(a-b)))%mod*inv(fact(b))%mod;
}

struct edge{
	int from;
	int to;
	long long len;
	int next;
	edge(){
		
	}
	edge(int u,int v,long long w,int hd){
		from=u;
		to=v;
		len=w;
		next=hd;
	}
	friend bool operator <(edge a,edge b){
		return a.len<b.len;
	}
}E[maxm];
int head[maxn];
int sz=0;
void add_edge(int u,int v,long long w){
	sz++;
	E[sz]=edge(u,v,w,head[u]);
	head[u]=sz;
}

int fa[maxn];
inline void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
inline int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
long long kruskal(){
	init();
	sort(E+1,E+1+m);
	int x,y,fx,fy;
	long long ans=0;
	for(int i=1;i<=m;i++){
		x=E[i].from;
		y=E[i].to;
		fx=find(x);
		fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=E[i].len;
		}
	}
	return ans;
} 

int cnt(){
	
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
//	freopen("t46.in","r",stdin);
	int u,v;
	long long w;
	scanf("%d %d %lld",&n,&m,&V);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		add_edge(u,v,w);
	}
	long long minv=kruskal();
	if(V<minv){
		printf("0\n");
	}else if(V==minv){
		printf("%lld\n",C(m,n-1)%mod*(fast_pow(2,n-1)-2)%mod*(fast_pow(2,m-n))%mod);
	}
}
