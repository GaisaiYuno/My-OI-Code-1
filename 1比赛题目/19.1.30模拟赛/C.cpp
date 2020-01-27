/*
For my love Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000
#define maxv 10000
#define mod 1000000007
using namespace std;
int n;
int a[maxn+5];
long long dp[2][maxv*10+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long ans=0;
	int o=1;
	for(int i=1;i<=n;i++){
		dp[o^1][maxv]++;
		for(int j=0;j<=maxv*2;j++){
			if(j-a[i]>=0&&j+a[i]<=maxv*2)dp[o][j]=dp[o^1][j-a[i]]+dp[o^1][j+a[i]];
			dp[o][j]%=mod;
		}
		ans=(ans+dp[o][maxv])%mod;
		o^=1;
	}
	printf("%lld\n",ans);
}
