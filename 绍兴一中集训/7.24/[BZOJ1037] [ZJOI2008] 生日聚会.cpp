#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 150
#define maxk 20
#define mod 12345678
using namespace std;
int n,m,k;
long long dp[maxn+5][maxn+5][maxk+5][maxk+5];
//dp[i][j][x][y] 表示前i+j个，i个男，j个女，任意子串中，男的比女的最多多x个，女的比男的最多多y个的方案数 
int main(){
	scanf("%d %d %d",&n,&m,&k);
	dp[0][0][0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int x=0;x<=k;x++){
				for(int y=0;y<=k;y++){
					if(i+1<=n&&x+1<=k){
						dp[i+1][j][x+1][max(y-1,0)]+=dp[i][j][x][y];
						dp[i+1][j][x+1][max(y-1,0)]%=mod;
					}
					if(j+1<=m&&y+1<=k){
						dp[i][j+1][max(x-1,0)][y+1]+=dp[i][j][x][y];
						dp[i][j+1][max(x-1,0)][y+1]%=mod;
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			ans+=dp[n][m][i][j];
			ans%=mod;
		}
	}
	printf("%lld\n",ans);
}
