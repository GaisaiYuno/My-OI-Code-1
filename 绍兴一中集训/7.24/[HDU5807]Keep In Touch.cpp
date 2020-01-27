#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50
#define mod 998244353 
using namespace std;
int t,n,lim,m,q;
int w[maxn+5];
int g[maxn+5][maxn+5];
int dp[maxn+5][maxn+5][maxn+5][3];
void ini(){
	memset(g,0,sizeof(g));
	memset(dp,0,sizeof(dp));
}
int main(){
	int u,v,a,b,c;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		ini();
		scanf("%d %d %d %d",&n,&m,&lim,&q);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]); 
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			g[u][v]=1;
		}
		for(int i=n;i>=1;i--){//题目要求u<v,所以倒推 
			for(int j=n;j>=1;j--){
				for(int k=n;k>=1;k--){
					dp[i][j][k][0]=1;
					dp[i][j][k][1]=0;
					dp[i][j][k][2]=0;
					for(int u=i+1;u<=n;u++){
						if(g[i][u]){
							dp[i][j][k][0]+=dp[u][j][k][2];
							dp[i][j][k][0]%=mod;
						}
					}
					for(int u=j+1;u<=n;u++){
						if(g[j][u]){
							dp[i][j][k][1]+=dp[i][u][k][0];
							dp[i][j][k][1]%=mod;
						}
					}
					for(int u=k+1;u<=n;u++){
						if(g[k][u]){
							dp[i][j][k][2]+=dp[i][j][u][1];
							dp[i][j][k][2]%=mod;
						}
					}
					if(max(max(abs(w[i]-w[j]),abs(w[i]-w[k])),abs(w[j]-w[k]))>lim) dp[i][j][k][0]=0;
				} 
			} 
		}
		for(int i=1;i<=q;i++){
			scanf("%d %d %d",&a,&b,&c);
			printf("%d\n",dp[a][b][c][0]);
		}
	} 
}

