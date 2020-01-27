#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> g[100001];
int n,k,dp[21][100001];

void dddddddp(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i==1){
				dp[i][j]=dp[i-1][j];
				for(int k=0;k<g[j].size();k++){
					int v=g[j][k];
					dp[i][j]+=dp[i-1][v];
				}
			}
			else {
				dp[i][j]=dp[i-2][j];
				for(int k=0;k<g[j].size();k++){
					int v=g[j][k];
					dp[i][j]+=dp[i-1][v]-dp[i-2][j];
				}
			}
		}
	}
}

int main(){
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&dp[0][i]);
	}
	dddddddp();
	for(int i=1;i<=n;i++)cout<<dp[k][i]<<'\n';
}
