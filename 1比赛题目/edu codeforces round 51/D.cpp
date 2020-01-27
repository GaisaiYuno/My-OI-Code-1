#include<iostream>
#include<cstdio>
#define maxn 1005
#define mod 998244353
using namespace std;
int n,m;
long long dp[maxn][maxn*2][2];
int main() {
	scanf("%d %d",&n,&m);
	dp[1][1][0]=2;
	dp[1][2][1]=2;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			dp[i][j][0]+=dp[i-1][j-1][0]+dp[i-1][j][0]+dp[i-1][j][1]*2;
			dp[i][j][0]%=mod;
			dp[i][j][1]+=dp[i-1][j-2][1]+dp[i-1][j][1]+dp[i-1][j-1][0]*2;
			dp[i][j][1]%=mod;
		}
	}
	printf("%I64d\n",(dp[n][m][0]+dp[n][m][1])%mod);
}
