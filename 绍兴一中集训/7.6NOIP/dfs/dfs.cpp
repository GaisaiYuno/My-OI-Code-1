#include<iostream>
#include<cstdio>
#define maxn 3000
#define mod 1000000007
using namespace std;
int n;
int a[maxn+5];
long long dp[maxn+5][maxn+5];
long long suf[maxn+5];
int main(){
#ifndef LOCAL
	freopen("dfs.in","r",stdin);
	freopen("dfs.out","w",stdout);
#endif


	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n>3000){
		printf("0\n");
		return 0;
	}
	
	if(a[1]>0){
		printf("0\n");
		return 0;
	}else{
		dp[1][0]=1;
		for(int j=n-1;j>=0;j--){
			suf[j]=suf[j+1]+dp[1][j];
			suf[j]%=mod;
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=-1){
			if(a[i]==0){
				printf("0\n");
				return 0;
			}
			for(int j=a[i]-1;j<=n-1;j++){
				dp[i][a[i]]+=dp[i-1][j];
				dp[i][a[i]]%=mod;
			}
		}else{
			for(int j=1;j<=n-1;j++){
//				for(int k=j-1;k<=n-1;k++){
//					dp[i][j]+=dp[i-1][k];
//					dp[i][j]%=mod;
//				}
				dp[i][j]+=suf[j-1];
				dp[i][j]%=mod;
			}
		}
		for(int j=n-1;j>=0;j--){
			suf[j]=suf[j+1]+dp[i][j];
			suf[j]%=mod;
		}
	}
	long long ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=dp[n][i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
