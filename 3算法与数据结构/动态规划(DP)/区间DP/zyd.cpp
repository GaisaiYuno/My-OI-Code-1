#include<iostream>
#include<cstring>
#define maxn 1005
int a[maxn],sum[maxn];
int n;
long long dp[maxn][maxn];
using namespace std;
int main(){
	int cnt=0; 
	while(cin>>n){ 
	    memset(sum,0,sizeof(sum));
	    for(int i=1;i<=n;i++){
	    	for(int j=i;j<=n;j++){//这样dp[i][j]=0 
	    		dp[i][j]=0xffffffff;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=n;i>=1;i--){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=j;k++){
			   		dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]+a[i]*(k-1)+(k-i+1)*(sum[k]-sum[i]));
		    	}
			}
		}
		cnt++;
		printf("Case #%d: %d\n",cnt,dp[1][n]);
	} 
}
/*状态转移方程 
    子状态 dp[i][j] 从第i只到第j只造成的最小伤害
    1) dp[i][j] 以a[i]为第1个上场，以a[j]为最后上场造成的最小伤害  序列只有a[i] a[i+1] ……a[j] 
       a[i]*(1-1)+a[i+1]*(2-1）+……+a[j](j-1) 
    2) dp[i][j] 以a[i]为第i个上场，以a[j]为最后上场造成的最小伤害
       将1)放到dp[i+1][k]+dp[k+1][j]里, 区间偏移 
	dp[i][j]=min(dp[i][k-1]+dp[k+1][j]+a[i]*(k-1)+dp[k-i+1]*,dp[i][j]) 

*/ 
