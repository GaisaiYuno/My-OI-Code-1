#include<iostream>
#include<cstring>
#define maxk 7
#define maxn 41
using namespace std;
int k,n;
char s[maxk];
long long dp[maxn][maxk];
int tonum(int l,int r) {
	long long x=0;
	for(int i=l; i<=r; i++) {
		x=x*10+s[i]-'0';
	}
	return x;
}
int main() {
	//freopen("cjzd.in","r",stdin);
	//freopen("cjzd.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0; i<n; i++) {
		dp[i][0]=tonum(0,i);
	}
	for(int i=0; i<n; i++) {
		for(int j=1; j<=k; j++) {
			for(int u=j-1; u<i; u++) {
				dp[i][j]=max(dp[i][j],dp[u][j-1]*tonum(u+1,i));
			}
		}
	}
	cout<<dp[n-1][k]<<endl;
}
/*
dp[i][j]=dp[u][j-1]*tonum(u+1,i)
  u¡Ê[j,i]
*/
