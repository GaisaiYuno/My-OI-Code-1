#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define mod 1000000007
using namespace std;
long long dp[maxn*4+5];
int n,k;
int main(){
	cin>>n>>k;
	dp[0]=1;
	for(int i=0;i<maxn;i++){
		dp[i+1]+=dp[i];
		dp[i+k]+=dp[i];
		dp[i+1]%=mod;
		dp[i+k]%=mod;
	}
	for(int i=1;i<=maxn;i++){
		dp[i]=(dp[i]+dp[i-1])%mod;
	}
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(dp[b]-dp[a-1]<0) printf("%I64d\n",dp[b]-dp[a-1]+mod);
		else printf("%I64d\n",dp[b]-dp[a-1]);
	}
}
