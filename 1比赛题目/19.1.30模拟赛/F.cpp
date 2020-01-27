#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define maxk 55
#define mod 1000000007
using namespace std;
int n,k;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

long long dp[maxn][maxk];
long long f[maxn];
int dfs(int x,int fa){
	dp[x][0]=dp[x][k+1]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			memset(f,0,sizeof(f));
			for(int j=0;j<=2*k;j++){
				for(int u=0;u<=2*k;u++){
					if(j+u<=2*k){
						f[min(j,u+1)]+=dp[x][j]*dp[y][u]%mod;
						f[min(j,u+1)]%=mod;
					}else{
						f[max(j,u+1)]+=dp[x][j]*dp[y][u]%mod;
						f[max(j,u+1)]%=mod; 
					}
				}
			}
			memcpy(dp[x],f,sizeof(f));
		}
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	long long ans=0;
	for(int i=0;i<=k;i++){
		ans+=dp[1][i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}

