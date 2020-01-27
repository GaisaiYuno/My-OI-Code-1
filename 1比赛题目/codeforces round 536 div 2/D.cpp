#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
int vis[maxn];
vector<int>E[maxn];
vector<int>seq;
void dfs(int x){
	vis[x]=1;
	seq.push_back(x);
	for(auto y : E[x]){
		if(!vis[y]){
			dfs(y);
		}
	}
}
int main(){
	int u,v; 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
	}
	dfs(1);
	for(int i=0;i<n;i++){
		printf("%d ",seq[i]);
	}
}

