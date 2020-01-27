#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define mod 1000000007
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int siz=1;
int head[maxn];
void add_edge(int u,int v){
	siz++;
	E[siz].from=u;;
	E[siz].to=v;
	E[siz].next=head[u];
	head[u]=siz;
}

int sz[maxn];
int vis[maxn];
void dfs(int x,int fa){
	vis[x]=1;
	sz[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
}

int n,k;
int main(){
	int u,v,w;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d %d",&u,&v,&w);
		if(w==0){
			add_edge(u,v);
			add_edge(v,u);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0);
			ans+=fast_pow(sz[i],k);
			ans%=mod;
		}
	}
	ans=(fast_pow(n,k)-ans+mod)%mod;
	printf("%I64d\n",ans);
}

