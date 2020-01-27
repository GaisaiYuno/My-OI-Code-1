//https://www.cnblogs.com/Miracevin/p/9657177.html
/*
Problem:会议中心[APIO2009]
Source:http://111.230.183.91/contest/14/problem/8
Algorithm:
Description:
*/
#include<iostream>
#include<cstdio>
#define maxn 1505
using namespace std;
int n,m,k;
int a[maxn][maxn];
int sum[maxn][maxn];

void ini() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	for(int i=n; i>=k; i--) {
		for(int j=m; j>=k; j--) {
			sum[i][j]-=sum[i-k][j]+sum[i][j-k]-sum[i-k][j-k];
		}
	}
}


int upl[maxn][maxn];
int downl[maxn][maxn];
int upr[maxn][maxn];
int downr[maxn][maxn];
int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	ini();
	for(int i=k; i<=n; i++) {
		for(int j=k; j<=m; j++) {
			upl[i][j]=max(sum[i][j],max(upl[i-1][j],upl[i][j-1]));
		}
	}
	for(int i=k; i<=n; i++) {
		for(int j=m; j>=k; j--) {
			upr[i][j]=max(sum[i][j],max(upr[i-1][j],upr[i][j+1]));
		}
	}
	for(int i=n; i>=k; i--) {
		for(int j=k; j<=m; j++) {
			downl[i][j]=max(sum[i][j],max(downl[i][j-1],downl[i+1][j]));
		}
	}
	for(int i=n; i>=k; i--) {
		for(int j=m; j>=k; j--) {
			downr[i][j]=max(sum[i][j],max(downl[i+1][j],downl[i][j+1]));
		}
	}

	int ans=0;
	for(int i=k; i<=n-k; i++) {
		for(int j=k; j<=m-k; j++) {
			ans=max(ans,upl[i][j]+upr[i][j+k]+downl[i+k][m]);
		}
	}
	for(int i=k+k; i<=n; i++) {
		for(int j=k; j<=m-k; j++) {
			ans=max(ans,downl[i][j]+downr[i][j+k]+upl[i-k][m]);
		}
	}
	for(int i=k; i<=n-k; i++) {
		for(int j=k; j<=m-k; j++) {
			ans=max(ans,upl[i][j]+downl[i+k][j]+upr[n][j+k]);
		}
	}
	for(int i=k; i<=n-k; i++) {
		for(int j=k+k; j<=m; j++) {
			ans=max(ans,upl[n][j-k]+upr[i][j]+downr[i+k][j]);
		}
	}
	for(int i=k; i<=n-k; i++) {
		for(int j=k+k; j<=m-k; j++) {
			ans=max(ans,sum[i][j]+upl[n][j-k]+upr[n][j+k]);
		}
	}
	for(int i=k+k; i<=n-k; i++) {
		for(int j=k; j<=m; j++) {
			ans=max(ans,sum[i][j]+upl[i-k][m]+downl[i+k][m]);
		}
	}
	printf("%d",ans);
}

