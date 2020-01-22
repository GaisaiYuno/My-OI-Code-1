#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10005
using namespace std;
int n,m,k;
vector<int>G[maxn];
int dp[maxn];
int in[maxn];
int get_d(){
	queue<int>q;
	q.push(1);
	dp[1]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto y : G[x]){
			in[y]--;
			dp[y]=max(dp[y],dp[x]+1);
			if(!in[y]){
				q.push(y);
			}
		}
	}
 	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[n]);
	return ans;
}
int main(){
	int x,y;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		in[y]++;
	}	
	printf("%d\n",get_d());
}
