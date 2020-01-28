#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 20
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int g[maxn][maxn];
int dp[1<<16][maxn];//dp[i][j]表示点集为i，链的终点为j时边的长度的最大值 
int sum[1<<16];//sum[S] 表示点集S中所有边权之和 
int main() {
	int u,v,w;
	int ans=0;
	scanf("%d %d",&n,&m);
	memset(g,~0x3f,sizeof(g));
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&u,&v,&w);
		g[u-1][v-1]=g[v-1][u-1]=w;
		ans+=w;
	}
	for(int i=1; i<(1<<n); i++) {
		int pos;//i中最高位的1的位置， 
		for(int j=0; j<n; j++) {
			if(i&(1<<j) )pos=j;
		}
		sum[i]=sum[i^(1<<pos)];//i^(1<<(pos-1)))是i除去当前点的点集
		for(int j=0; j<n; j++) {
			if(i&(1<<j)) {
				if(g[pos][j]>0) {
					sum[i]+=g[pos][j];
				}
			}
		}
	}
	memset(dp,~0x3f,sizeof(dp));
	for(int i=1; i<=(1<<n)-1; i+=2) {
		dp[i][0]=sum[i];
		for(int j=0; j<n; j++) {
			if(dp[i][j]!=-1061109568) {
				int left=((1<<n)-1)^i;//i的补集，即未加入i的点 
				for(int sub=left; sub; sub=(sub-1)&left) {//sub为与i相连的连通块 连接点在j 
					dp[i|sub][j]=max(dp[i|sub][j],dp[i][j]+sum[sub|(1<<j)]);//加连通块进去 
				}
				for(int k=0; k<n; k++) {
					if(!((1<<k)&i)) {
						dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+g[j][k]);//链加长，端点到k 
					}
				}
			}
		}
	}

	printf("%d\n",ans-dp[(1<<n)-1][n-1]);
}
