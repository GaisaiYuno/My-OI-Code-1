#include<bits/stdc++.h>
#define zhh 100001
#define x 1000
using namespace std;
typedef long long LL;
const int INF = 1<<30;
int dfn[zhh],low[zhh];
int jishi,ans;
vector<int> g[zhh];
void dfs(int u,int fa) {
	dfn[u]=low[u]=jishi++;
	bool flag=false;
	for(int i=0; i<g[u].size(); i++) {
		int v = g[u][i];
		if(v==fa && !flag) { //如果有重边，那么边(u,v)被存了两次，所以，如果第二次访问，就让他通过
			flag = true;
			continue;
		}
		if(dfn[v]==0)  dfs(v,u);
		low[u]=min(low[u],low[v]);
		if(low[v]>dfn[u]) ans++;
	}
}
int main() {
	int n,m,i,a,b,cnt=0;
	cin>>m>>n;
	cnt++;
	for(i=0; i<m; i++) {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		dfs(1,-1);
		cout<<ans;
	}
}
return 0;
}

