#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 200000
using namespace std;
typedef long long ll;
int n;
vector<int>E[maxn+5];
ll sz[maxn];
ll dp1[maxn+5],dp2[maxn+5];

void dfs1(int x,int fa){
	sz[x]=1;
	for(int y : E[x]){
		if(y!=fa){
			dfs1(y,x);
			sz[x]+=sz[y];
		}
	} 
}

void dfs2(int x,int fa){
	dp1[x]=1;
	for(int y : E[x]){
		if(y!=fa){
			dfs2(y,x);
			dp1[x]+=dp1[y]+sz[y]*(n-sz[x]);
		}
	} 
}

void dfs3(int x,int fa){
	
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
	dfs2(1,0);
	printf("%d\n",dp1[1]);
}

