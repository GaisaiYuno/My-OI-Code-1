#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 5005
using namespace std;
int n;
int a[maxn];
int dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	n=unique(a+1,a+1+n)-a-1;
	dp[1][n]=0;
	for(int len=n-1;len>=1;len--){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
			if(i-1>=0&&j+1<=n&&a[i-1]==a[j+1]) dp[i][j]=max(dp[i][j],dp[i-1][j+1]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][i]);
	printf("%d\n",n-1-ans);
}
