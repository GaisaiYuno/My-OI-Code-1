//dp[x][i][1]表示x的子树中买i个物品的最小花费，且x使用劵
//dp[x][i][0]表示x的子树中买i个物品的最小花费，且x没用劵
//dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[y][k][0]);
//  x,y均不用 
//dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][1]);
// y用，则x必须用 
//dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][0]);
// x用，y可不用 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5005
using namespace std;
int n,b;
struct edge {
	int from;
	int to;
	int next;
} E[maxn<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v) {
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int sz[maxn];
long long dp[maxn][maxn][2];
int c[maxn];
int d[maxn];
void dfs(int x,int fa) {
	sz[x]=1;
	dp[x][0][0]=0;
	dp[x][1][0]=c[x];
	dp[x][1][1]=c[x]-d[x];
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y==fa) continue;
		dfs(y,x);
		for(int j=sz[x]; j>=0; j--) {
			for(int k=0; k<=sz[y]; k++) {
				dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[y][k][0]);
				dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][1]);
				dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][0]);

			}
		}
		sz[x]+=sz[y];
	}
}

int main() {
	int u;
	scanf("%d %d",&n,&b);
	scanf("%d %d",&c[1],&d[1]);
	for(int i=2; i<=n; i++) {
		scanf("%d %d %d",&c[i],&d[i],&u);
		add_edge(u,i);
		add_edge(i,u);
	}
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0);
	int ans=n;
	for(int i=n; i>=0; i--) {
		if(dp[1][i][0]<=b||dp[1][i][1]<=b) {
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
}
