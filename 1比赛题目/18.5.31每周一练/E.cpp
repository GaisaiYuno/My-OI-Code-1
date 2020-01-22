#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define maxbin 17
#define maxsize 1<<17
#define maxd 60
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[maxn];
int dp[maxn][maxsize];
int ans[maxn][maxsize];
const int prime[maxbin]= {2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,53};
int sta[maxd];
inline int abs(int x){
	return x>=0?x:-x;
} 
void print(int v,int s){
	if(v==1){
		printf("%d ",ans[v][s]);
		return;
	}
	print(v-1,s-sta[ans[v][s]]);
	printf("%d ",ans[v][s]);
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=2; i<maxd; i++) {
		for(int j=0; j<maxbin; j++) {
			if(i%prime[j]==0){
				sta[i]|=(1<<j);
			}
		}
	}
	memset(dp,0x7f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<maxsize; j++) {
			if(dp[i][j]==INF) continue;
			for(int k=1; k<maxd-1; k++) {
				if(sta[k]&j) continue;
				int x=(j|sta[k]);
				if(dp[i][x]>dp[i-1][j]+abs(a[i]-k)) {
					dp[i][x]=dp[i-1][j]+abs(a[i]-k);
					ans[i][x]=k;
				}
			}
		}
	}
	int minv=INF;
	int status=0;
	for(int i=0;i<maxsize;i++){
		if(minv>dp[n][i]){
			minv=dp[n][i];
			status=i;
		}
	}
//	printf("%d\n",minv);
	print(n,status);
}
