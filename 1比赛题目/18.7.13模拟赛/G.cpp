#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define maxk 15
#define mod 100000000
using namespace std;
int n1,n2,k1,k2;
long long dp[maxn][maxn][maxk][maxk];
int main(){
	scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
	dp[0][0][0][0]=1;
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			for(int u=0;u<=k1;u++){
				for(int v=0;v<=k2;v++){
					if(dp[i][j][u][v]==0) continue;
					if(i<n1&&u<k1){
						dp[i+1][j][u+1][0]+=dp[i][j][u][v];
						dp[i+1][j][u+1][0]%=mod;
					}
					if(j<n2&&v<k2){
						dp[i][j+1][0][v+1]+=dp[i][j][u][v];
						dp[i][j+1][0][v+1]%=mod;
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=k1;i++){
		ans+=dp[n1][n2][i][0];
		ans%=mod;
	} 
	for(int i=1;i<=k2;i++){
		ans+=dp[n1][n2][0][i];
		ans%mod;
	}
	printf("%I64d\n",ans%mod);
}
