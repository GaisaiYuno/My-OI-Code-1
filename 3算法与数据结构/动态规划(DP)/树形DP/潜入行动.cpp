//http://119.29.55.79/problem/407
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxk 100
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,k;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int esz=0;
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz; 
}

unsigned int dp[maxn+5][maxk+5][2][2];//x的子树中放了i个节点，x选/不选，x是否被覆盖 
ll cur[maxk+5][2][2];//临时存储还没加子树y的dp[x][i][0/1][0/1]， 
int sz[maxn+5];
void dfs(int x,int fa){
	sz[x]=1;
	dp[x][0][0][0]=dp[x][1][1][0]=1; 
	for(int p=head[x];p;p=E[p].next){
		int y=E[p].to;
		if(y!=fa){
			dfs(y,x);
			for(int i=0;i<=min(sz[x],k);i++){
				for(int j=0;j<=1;j++){
					for(int k=0;k<=1;k++){
						cur[i][j][k]=dp[x][i][j][k];
						dp[x][i][j][k]=0;
					}
				}
			}
			for(int i=0;i<=min(sz[x],k);i++){
				for(int j=0;j<=min(sz[y],k);j++){
					if(i+j>k) continue;
					dp[x][i+j][0][0]+=cur[i][0][0]*dp[y][j][0][1]%mod;
					dp[x][i+j][0][0]%=mod;
					dp[x][i+j][0][1]+=(cur[i][0][1]*(dp[y][j][0][1]+dp[y][j][1][1])%mod+cur[i][0][0]*dp[y][j][1][1])%mod;
					dp[x][i+j][0][1]%=mod;
					dp[x][i+j][1][0]+=cur[i][1][0]*(dp[y][j][0][0]+dp[y][j][0][1])%mod;
					dp[x][i+j][1][0]%=mod;
					dp[x][i+j][1][1]+=cur[i][1][0]*(dp[y][j][1][0]+dp[y][j][1][1])%mod+cur[i][1][1]*(dp[y][j][0][0]+dp[y][j][0][1]+dp[y][j][1][0]+dp[y][j][1][1])%mod;
					dp[x][i+j][1][1]%=mod;
				}
			}
			sz[x]+=sz[y];
		}
	}
}
int main(){
//	freopen("action3.in","r",stdin);
	int u,v;
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u); 
	}
	dfs(1,0);
	ll ans=0;
	ans+=dp[1][k][0][1]+dp[1][k][1][1];
	ans%=mod;
	printf("%lld\n",ans);
	return 0; 
}
