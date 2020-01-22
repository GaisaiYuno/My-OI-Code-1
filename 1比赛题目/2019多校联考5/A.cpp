#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxv 15
#define maxb (1<<16)
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[maxn+5];
int cnt[maxv+5];

int sta;
int dp[maxb+5];
int get_dp(int s) {
	if(dp[s]!=INF) return dp[s];
	for(int i=0; i<=15; i++) {
		if(!(s&(1<<i))) continue;
		for(int j=0; j<=15; j++) {
			if(!(s&(1<<j))||i==j) continue;
			int p=i^j;
			int rest=s^(1<<i)^(1<<j)^(1<<p);
			if(!(rest&(1<<p))) dp[s]=min(dp[s],get_dp(rest)+2); //i,j异或之后出现i^j，和原来的i^j一起被消掉
			else dp[s]=min(dp[s],get_dp(rest)+1);
		}
	}
	return dp[s];
}
int main() {
//#ifdef LOCAL
//	freopen("1.in","r",stdin);
//#endif 
	int u,v,w;
	scanf("%d",&n);
	for(int i=1; i<n; i++) {
		scanf("%d %d %d",&u,&v,&w);
		u++;
		v++;
		a[u]^=w;
		a[v]^=w;
	}
	for(int i=1; i<=n; i++) {
		cnt[a[i]]++;
	}
	int ans=0;
	for(int i=1; i<=15; i++) {
		ans+=cnt[i]/2;
		if(cnt[i]%2==1) sta|=(1<<i);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	ans+=get_dp(sta);
	printf("%d\n",ans);
}

