//我相信暴力出奇迹
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2505
#define INF 0x7fffffff
using namespace std;
int n,m;
int a[maxn*2][maxn*2];
int sum[maxn*2][maxn*2];
void init() {
	for(int i=1; i<=n*2; i++) {
		for(int j=1; j<=m*2; j++) {
			sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
		}
	}
	return;
}
int query(int x1,int y1,int x2,int y2) {
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int get_ans(int k) {
	int t=0;
	int cnt1=0;
	for(int i=1; i<=n; i+=k) {
		for(int j=1; j<=m; j+=k) {
			cnt1=query(i,j,i+k-1,j+k-1);
//			if(k==404&&cnt1<0) {
//				k=404;
//				printf("%d %d %d %d\n",i,j,i+k-1,j+k-1);
//				printf("%d",sum[i+k-1][j+k-1]);
//				cnt1=query(i,j,i+k-1,j+k-1);
//			}
			t+=min(cnt1,k*k-cnt1);

		}
	}
	return t;
}
int main() {
//	freopen("data.in","r",stdin);
//	freopen("debug.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%1d",&a[i][j]);
		}
	}
	init();
	int ans=INF;
	for(int i=2; i<=min(n,m); i++) {
		int t=get_ans(i);
//		printf("%d:%d\n",i,t);
		ans=min(ans,t);
	}
	printf("%d\n",ans);
}
