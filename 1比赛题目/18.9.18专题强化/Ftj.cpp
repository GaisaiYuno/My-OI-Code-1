#include <bits/stdc++.h>
using namespace std;
//using pi = pair<int, int>;
const int MAXN = 1005;
const int MAXM = 200005;
 
vector<int> gph[MAXN];
int adj[MAXN][MAXN], vis[MAXN];
int n, m;
int s[MAXM], e[MAXM];
 
void dfs(int r, int v){
	vis[v] = 1;
	adj[r][v]++;
	int cnt=gph[v].size();
	for(int it=0;it<cnt;it++){
		int i=gph[v][it];
		if(i == r) continue;
		if(!vis[i] && adj[r][i] < 2){
			dfs(r, i);
		}
	}
}
 
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		scanf("%d %d",&s[i],&e[i]);
		gph[s[i]].push_back(e[i]);
	}
	for(int i=1; i<=n; i++){
		int cnt=gph[i].size();
		for(int it=0;it<cnt;it++){
			int j=gph[i][it];
			if(adj[i][j] < 2){
				memset(vis, 0, sizeof(vis));
				dfs(i, j);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//	    for(int j=1;j<=n;j++){
//	        printf("%d ",adj[i][j]);
//	    }
//	    printf("\n");
//	}
	for(int i=0; i<m; i++){
		if(adj[e[i]][s[i]] == 0){
			puts(adj[s[i]][e[i]] > 1 ? "diff" : "same");
		}
		else{
			puts(adj[s[i]][e[i]] > 1 ? "same" : "diff");
		}
	}
}
