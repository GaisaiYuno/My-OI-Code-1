#include<iostream>
#include<cstdio>
#define maxn 55
using namespace std;
int n,m;
int a[maxn][maxn];
int dp[2*maxn][maxn][maxn];
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	int p,q;
	for(int k=1; k<=n+m-1; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				p=k-i+1;
				q=k-j+1;
				if(p<1||p>m||q<1||q>m) continue;
				if(i!=j) {
					dp[k][i][j]=max(max(dp[k-1][i][j],dp[k-1][i-1][j-1]),
					                max(dp[k-1][i-1][j],dp[k-1][i][j-1]))
					            +a[i][p]+a[j][q];
				} else {
					dp[k][i][j]=max(max(dp[k-1][i][j],dp[k-1][i-1][j-1]),
					                max(dp[k-1][i-1][j],dp[k-1][i][j-1]))
					            +a[i][p];
				}
			}
		}
	}
	printf("%d\n",dp[n+m-1][n][n]);
}
