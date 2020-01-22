#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define maxn 100000
#define maxm 26
#define maxk 50
using namespace std;
int n,m,K;
char str[maxn+5];

int dist[maxm+5][maxm+5];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}

int dp[maxn+5];
int cost[maxm+5][maxn+5];//cost[i][j]: [1,j]全部修改为字符i的代价
int fmin[maxm+5][maxn+5];
int main(){
#ifndef LOCAL
	freopen("cowmbat.in","r",stdin);
	freopen("cowmbat.out","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&K);
	scanf("%s",str+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) scanf("%d",&dist[i][j]);
	} 
	floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cost[j][i]=cost[j][i-1]+dist[str[i]-'a'+1][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int c=1;c<=m;c++) fmin[c][0]=0;
	for(int i=1;i<=n;i++){
		for(int c=1;c<=m;c++){
			if(i-K>=0) dp[i]=min(fmin[c][i-K]+cost[c][i],dp[i]);
		}
		for(int c=1;c<=m;c++){
			fmin[c][i]=min(fmin[c][i-1],dp[i]-cost[c][i]);
		}
	}
	printf("%d\n",dp[n]); 
}
