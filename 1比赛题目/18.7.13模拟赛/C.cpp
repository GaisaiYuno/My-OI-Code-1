#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
int t[maxn];
long long dp[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	int p90=0,p1440=0;
	for(int i=1;i<=n;i++){
		while(t[p90]+90-1<t[i]) p90++;
		while(t[p1440]+1440-1<t[i]) p1440++;
//		printf("%d %d\n",p90,p1440);
		dp[i]=min(min(dp[i-1]+20,dp[p90-1]+50),dp[p1440-1]+120);
	}
	for(int i=1;i<=n;i++){ 
		printf("%d\n",dp[i]-dp[i-1]);
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",dp[i]);
//	}
} 
