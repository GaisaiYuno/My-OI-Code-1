#include<iostream>
#include<cstdio>
#include<vector> 
#define maxn 300005
#define INF 0x3f3f3f3f
using namespace std;
int n;
vector<int>E[maxn];
int is_max[maxn];
int dp[maxn];//该节点是子树中第dp[i]大的 
int leaf_cnt;
void dfs(int x,int fa){
	if(E[x].size()==1&&x!=1){
		dp[x]=1;
		leaf_cnt++;
		return;
	} 
	else{
		if(is_max[x]) dp[x]=INF;
		else dp[x]=0;
	}
	for(int y : E[x]){
		if(y==fa) continue;
		dfs(y,x);
		if(is_max[x]){
			dp[x]=min(dp[y],dp[x]);
		}else{
			dp[x]+=dp[y];
		} 
	}
}
int main(){
	int f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&is_max[i]);
	}
	leaf_cnt=0;
	for(int i=2;i<=n;i++){
		scanf("%d",&f);
		E[f].push_back(i);
		E[i].push_back(f);
	}
	dfs(1,0);
	printf("%d\n",leaf_cnt-(dp[1]-1));
}

