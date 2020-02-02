#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>
#define maxn 10000
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
int n,m,t;
int a[maxn+5];
pii dp[maxn+5];//前i首歌选j首的(最小光盘数，时间之和) 
int main(){
	scanf("%d %d %d",&n,&t,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0]=make_pair(0,0);
	for(int i=1;i<=n;i++) dp[i]=make_pair(INF,INF);
	for(int i=1;i<=n;i++){
//		if(a[i]>t) continue;
		for(int j=i;j>0;j--){
			pii now;
			if(dp[j-1].second+a[i]<=t) now=make_pair(dp[j-1].first,dp[j-1].second+a[i]);
			else now=make_pair(dp[j-1].first+1,a[i]);
			dp[j]=min(dp[j],now); 
//			if(now<dp[j]) dp[j]=now;
		}
	}
	for(int j=n;j>=0;j--){
		if(dp[j].first<m){
			printf("%d",j);
			break;
		}
	}
}

