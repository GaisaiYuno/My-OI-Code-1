#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,m;
ll dp[2][maxn+5][maxn+5];
ll sum[maxn+5][maxn+5];
inline int get_sum(int x1,int y1,int x2,int y2) {
	return (sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]+mod+mod)%mod;
}
int main() {
	scanf("%d %d",&n,&m);
	int now=0;
	for(int j=1; j<=n; j++) {
		for(int k=j; k<=n; k++) dp[now][j][k]=1;
	}
	for(int j=1; j<=n; j++) {
		for(int k=1; k<=n; k++) {
			sum[j][k]=(dp[now][j][k]+sum[j-1][k]+sum[j][k-1]-sum[j-1][k-1]+mod)%mod;
		}
	}
	now^=1; 
	for(int i=2; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) dp[now][j][k]=0;
		}
		for(int j=1; j<=n; j++) {
			for(int k=j; k<=n; k++) {
				dp[now][j][k]=get_sum(1,k,j,n);
			}
		}
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				sum[j][k]=(dp[now][j][k]+sum[j-1][k]+sum[j][k-1]-sum[j-1][k-1]+mod)%mod;
			}
		}
		now^=1;
	}
	ll ans=0;
	for(int j=1; j<=n; j++) {
		for(int k=1; k<=n; k++) ans=(ans+dp[now^1][j][k])%mod;
	}
	printf("%I64d\n",ans);
}

