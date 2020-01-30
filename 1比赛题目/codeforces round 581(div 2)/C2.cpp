#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#define maxn 100
#define maxm 1000000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int a[maxm+5];
int g[maxn+5][maxn+5];
int dist[maxn+5][maxn+5];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){	
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
}
int last[maxm+5];
int dp[maxm+5];
vector<int>ans;
void print(int x){
	if(x!=1) print(last[x]);
	printf("%d ",a[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&g[i][j]);
			if(g[i][j]==0&&i!=j) g[i][j]=INF; 
		}
	}
	memcpy(dist,g,sizeof(g));
	floyd();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1]=1;
	for(int i=2;i<=m;i++){
		for(int j=max(i-n,1);j<i;j++){
			if(dist[a[j]][a[i]]==i-j){
				if(dp[i]>dp[j]+1){
					dp[i]=dp[j]+1;
					last[i]=j;
				}
			} 
		}
	} 
	printf("%d\n",dp[m]);
	print(m);
}

