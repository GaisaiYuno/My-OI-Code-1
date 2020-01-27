#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,m;
ll dp[2][maxn+5];
int main(){
	scanf("%d %d",&m,&n);
	int now=0;
	for(int i=1;i<=m;i++) dp[1][i]=1;
	for(int i=2;i<=n;i++){
		now^=1;
		for(int j=1;j<=m;j++) dp[now^1][j]=0;
		for(int j=1;j<=m;j++){
			for(int k=1;j*k<=m;k++){
				dp[now^1][j*k]+=dp[now][j];
				dp[now^1][j*k]%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		ans+=dp[now^1][i];
		ans%=mod; 
	}
	printf("%lld\n",ans);
}

