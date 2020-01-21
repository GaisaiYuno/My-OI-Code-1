/*
Problem:聪聪可可
Source:http://119.29.55.79/contest/28/problem/4
Description: 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20005 
using namespace std;
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
int n;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<1];
int ecnt=1;
int head[maxn];
inline void add_edge(int u,int v,int w){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	E[ecnt].len=w;
	head[u]=ecnt;
}

int root=0,sum;
int f[maxn];
int sz[maxn];
int vis[maxn];
void get_root(int x,int fa){
	f[x]=0;
	sz[x]=1;
	for(register int i=head[x];i;i=E[i].next){
		register int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_root(y,x);
			sz[x]+=sz[y];
			f[x]=max(f[x],sz[y]);
		}
	}
	f[x]=max(f[x],sum-f[x]);
	if(f[x]<f[root]) root=x;
} 

int cnt=0;
int deep[maxn];
int res[maxn];
void get_deep(int x,int fa){
	res[++cnt]=deep[x];
	for(register int i=head[x];i;i=E[i].next){
		register int y=E[i].to;
		if(y!=fa&&!vis[y]){
			deep[y]=deep[x]+E[i].len;
			get_deep(y,x);
		}
	}
}

long long calc(int x,int d0){
	deep[x]=d0;
	cnt=0;
	get_deep(x,0);
	register long long p0,p1,p2;
	p0=p1=p2=0;
	long long ans=0;
	for(int i=1;i<=cnt;i++){
		if(res[i]%3==1) p1++;
		else if(res[i]%3==2) p2++;
		else p0++;
	}
	ans+=p0*p0+p1*p2*2;
	return ans;	 
}

long long ans=0;
void solve(int x){
//	printf("divide:%d\n",x);
	ans+=calc(x,0);
	vis[x]=1;
	for(register int i=head[x];i;i=E[i].next){
		register int y=E[i].to;
		if(!vis[y]){
			ans-=calc(y,E[i].len);
			sum=sz[y];
			root=0;
			get_root(y,0);
			solve(root);
		}
	}
}

int main(){
#ifdef FILE_INPUT
	freopen("5.in","r",stdin);
#endif 
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	sum=f[0]=n;
	root=0;
	get_root(1,0);//记得先处理一个根 
	solve(root);
	long long up=ans,down=(long long)n*n;
	long long g=gcd(up,down);
	printf("%lld/%lld\n",up/g,down/g);
}

