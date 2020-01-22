#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
int n;
vector<int>E[maxn+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}

int sg[maxn+5];
void dfs(int x,int fa){
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs(y,x);
			sg[x]^=(sg[y]+1); 
		}
	}
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v); 
	}
	dfs(1,0);
	if(sg[1]==0) printf("Bob\n");
	else printf("Alice\n"); 
}

