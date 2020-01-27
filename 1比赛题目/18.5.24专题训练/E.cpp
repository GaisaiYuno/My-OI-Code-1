#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x7f7f7f7f
#define maxn 105
using namespace std;
int a[maxn];
long long dp[maxn][maxn];
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int j;
		for(int len=2;len<n;len++){
			for(int i=2;i+len-1<=n;i++){
				j=len+i-1;
				dp[i][j]=INF;
				for(int k=i;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
				}
			}
		}
		printf("%I64d\n",dp[2][n]);
	}
} 
