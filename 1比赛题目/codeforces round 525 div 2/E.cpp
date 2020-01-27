//树形DP
//第一次DP求出每个块内最大的值，dp[x]表示以x为根的子树中最大权值和（必须选x)
//DP完就得到所有块中的最大值ans 
//又因为要求块最多
//我们再DP一次，一旦当前的dp[x]=ans时，说明当前块已经满足条件，k++ 
// 由于块不能互相包含，我们令dp[x]=0，这样计算x的祖先节点的子树时该块一定不会被包含（权值为0) 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 300005
#define INF 0x7ffffffffffffff
using namespace std;
int n,k;
long long ans=0;
int a[maxn];
long long dp[maxn];
vector<int>E[maxn];
void dfs1(int x,int fa){
	dp[x]=a[x];
	for(auto y : E[x]){
		if(y!=fa){
			dfs1(y,x);
			dp[x]+=max(dp[y],0ll);
		}
	}
	ans=max(ans,dp[x]);
}
void dfs2(int x,int fa){
	dp[x]=a[x];
	for(auto y : E[x]){
		if(y!=fa){
			dfs2(y,x);
			dp[x]+=max(dp[y],0ll);
		}
	}
	if(dp[x]==ans){
		k++;
		dp[x]=0;
	}
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=-INF;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%I64d %d\n",ans*k,k);
}
