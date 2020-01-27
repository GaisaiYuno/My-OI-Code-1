#include<iostream>
#include<cstdio>
#define maxn 500005
using namespace std;
int n;
long long a[maxn];
int dp[maxn];
int ans=0;
int top=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]*2>=a[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}
