/*
For my love Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
long long cnt[maxn];
long long dp[maxn][2];
int a[maxn];
long long ans=0;
int main(){
	scanf("%d",&n);
	int mv=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mv=max(mv,a[i]);
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=mv;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(cnt[i-1]) dp[i][1]=dp[i-1][0]+i*cnt[i];
		else dp[i][1]=max(dp[i-1][0],dp[i-1][1])+i*cnt[i];
	}
	printf("%lld\n",max(dp[mv][0],dp[mv][1]));
}
