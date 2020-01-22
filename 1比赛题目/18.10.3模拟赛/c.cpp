#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x7f7f7f7f7f7f7f7f
#define maxn 71
using namespace std;
long long n;
int ma,mb,mc;
long long dp[maxn][maxn][maxn];
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>ma>>mb>>mc;
	memset(dp,0x7f,sizeof(dp));
	dp[0][0][0]=n;
	long long ans=INF;
	for(int i=0; i<=ma; i++) {
		for(int j=0; j<=mb; j++) {
			for(int k=0; k<=mc; k++) {
				if(i==0&&j==0&&k==0) continue;
				if(i!=0)dp[i][j][k]=min(dp[i-1][j][k]/2,dp[i][j][k]);
				if(j!=0)dp[i][j][k]=min((dp[i][j-1][k]+1)/2,dp[i][j][k]);
				if(k!=0) {
					if(dp[i][j][k-1]==0) dp[i][j][k]=min(0ll,dp[i][j][k]);
					else dp[i][j][k]=min((dp[i][j][k-1]-1)/2,dp[i][j][k]);
				}
				ans=min(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans;
}
