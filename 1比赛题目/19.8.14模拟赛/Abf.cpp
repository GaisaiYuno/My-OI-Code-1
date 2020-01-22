#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
typedef long long ll;
int n;
int a[maxn+5];
ll dp[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int best=0;
		for(int j=0;j<i;j++){
			if(dp[i]>dp[j]+a[i]+(i-j)*(i-j-1)/2){
				dp[i]=dp[j]+a[i]+(i-j)*(i-j-1)/2;
				best=j;
			}
//			dp[i]=min(dp[i],);
		}
		printf("best=%d dp[%d]=%lld\n",best,i,dp[i]);
	}
	printf("%lld\n",dp[n]);
}
