#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 205
#define maxv 200000
#define INF 2147483647
using namespace std;
int dp[maxv+5];
int s[maxn],f[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=maxv;i++) dp[i]=-INF;
		dp[maxv/2]=0;
		for(int i=1;i<=n;i++) scanf("%d %d",&s[i],&f[i]);
		for(int i=1;i<=n;i++){
			if(s[i]<0&&f[i]<0) continue;
			if(s[i]<0){
				for(int j=s[i];j<=maxv+s[i];j++){
					if(dp[j-s[i]]>-INF) dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
				}
			}else{
				for(int j=maxv;j>=s[i];j--){
					if(dp[j-s[i]]>-INF) dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
				}
			}
		}
		int ans=-INF;
		for(int i=maxv/2;i<=maxv;i++){
			if(dp[i]>=0) ans=max(ans,dp[i]+i-maxv/2);
		}
		printf("%d\n",ans);
	}
} 
