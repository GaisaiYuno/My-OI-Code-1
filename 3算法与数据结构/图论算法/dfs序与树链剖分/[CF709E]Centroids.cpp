#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 400000
using namespace std;
int n;
vector<int>E[maxn+5];
int dp[maxn+5];//子树中可以切出来的最大节点数 
int max1[maxn+5];
int max2[maxn+5];
int sz[maxn+5];
void dfs1(int x,int fa){
	sz[x]=1;
	dp[x]=0;
	for(int y : E[x]){
		if(y!=fa){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(dp[y]>dp[x]){
				dp[x]=dp[y];
				max2[x]=max1[x];
				max1[x]=y;
			}else if(dp[y]>dp[max2[x]]) max2[x]=y; 
		}
	}
	if(sz[x]<=n/2) dp[x]=sz[x];
}

int ans[maxn+5];
void dfs2(int x,int fa,int pre){
	int flag=1;
	for(int y : E[x]){
		if(y==fa){
			if(n-sz[x]>n/2&&n-sz[x]-pre>n/2) flag=0;
		} 
		else if(sz[y]>n/2){
			if(sz[y]-dp[y]>n/2) flag=0;
		}
	}
	ans[x]=flag;
	for(int y : E[x]){
		if(y!=fa){
			int tmp;
			if(n-sz[y]<=n/2) tmp=n-sz[y];
			else{
				if(y==max1[x]) tmp=max(pre,dp[max2[x]]);//如果y在最大子树中，只能砍次大子树 
				else tmp=max(pre,dp[max1[x]]);	
			}
			dfs2(y,x,tmp);
		}
	}
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}	
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
