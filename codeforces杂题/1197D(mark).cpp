#include<iostream>
#include<cstdio>
#define maxn 300000
using namespace std;
typedef long long ll;
int n,m,k;
int a[maxn+5];
ll sum[maxn+5];
ll dp[maxn+5];//dp[i]表示前i个数的答案 
inline ll get_sum(int l,int r){
	return sum[r]-sum[l-1];
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll suf=0;
		ll maxsuf=0;
		//序列长度<m,直接找出(i-m,i)的最大连续后缀 
		for(int j=i-1;j>=max(i-m+1,1);j--){
			suf+=a[j];
			maxsuf=max(suf,maxsuf);
		}
		dp[i]=max(0ll,maxsuf+a[i]-k);//代价为k
		//长度>=m,增加代价k ,直接从i-m转移即可，因为i-m处长度>=0,总长度>=m 
		if(i-m>0) dp[i]=max(dp[i],dp[i-m]+get_sum(i-m+1,i-1)+a[i]-k);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	printf("%I64d\n",ans);
}

