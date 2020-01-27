#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxm 4000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
long long A,B,C;
struct node{
	int x;
	int y;
	long long p;
	long long q;
	friend bool operator < (node p,node q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	}
}a[maxm+5];
inline long long func(long long x){
	return A*x*x+B*x+C;
}

long long dp[maxm+5][maxm+5];
int main(){
#ifndef LOCAL
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
#endif
//	freopen("route3.in","r",stdin);
	scanf("%d %d %lld %lld %lld",&n,&m,&A,&B,&C);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld %lld",&a[i].x,&a[i].y,&a[i].p,&a[i].q);
	}
//	printf("ok\n");
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++){
		if(a[i].x==1) dp[1][i]=func(a[i].p);
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(j!=k&&a[j].p>=a[k].q&&a[j].x==a[k].y){
					dp[i][j]=min(dp[i-1][k]+func(a[j].p-a[k].q),dp[i][j]);
				}
			}
		}
	}
	long long ans=INF;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[j].y==n) ans=min(ans,dp[i][j]+a[j].q);
		}
		
	}
	printf("%lld\n",ans);
}

