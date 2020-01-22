#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int dp[maxn][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dp[1][0]=dp[1][1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) dp[i][1]=max(dp[i-1][1],dp[i-1][0]+1);
		else dp[i][1]=dp[i-1][1];
		if(a[i]<a[i-1]) dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
		else dp[i][0]=dp[i-1][0];
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
}
