#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n;
int a[maxn+5],b[maxn+5];
vector<ll>dp[maxn+5];
vector<ll>sum[maxn+5];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		dp[i].resize(b[i]-a[i]+1);
		sum[i].resize(b[i]-a[i]+1);
		for(int j=a[i];j<=b[i];j++){
			dp[i][j-a[i]]=1;
			for(int k=1;k<i;k++){
				if(j<a[k]) continue;
				else if(j>b[k]) dp[i][j-a[i]]+=sum[k][sum[k].size()-1];
				else dp[i][j-a[i]]+=sum[k][j-a[k]-1];
				dp[i][j-a[i]]%=mod;
			}
			sum[i][j-a[i]]=dp[i][j-a[i]];
		}
		for(int j=a[i]+1;j<=b[i];j++){
			sum[i][j-a[i]]+=sum[i][j-a[i]-1];
			sum[i][j-a[i]]%=mod;
		}
		ans+=sum[i][b[i]-a[i]];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
