#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100000
using namespace std;
int n,m;
vector<int>E[maxn+5];
vector<int>ans;
bool vis[maxn+5];
int tim[maxn+5];
int cnt[maxn+5];
void dfs(int x,int fa){
	ans.push_back(x);
	vis[x]=1;
	cnt[x]^=1;
	for(int y : E[x]){
		if(y!=fa&&!vis[y]){
			dfs(y,x);
			ans.push_back(x);
			cnt[x]^=1;
		}
	}
	if(fa!=0&&cnt[x]==1){
		ans.push_back(fa);
		ans.push_back(x);
		cnt[fa]^=1;
		cnt[x]^=1;
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
	for(int i=1;i<=n;i++) scanf("%d",&cnt[i]);
	int st=1;
	for(int i=1;i<=n;i++){
		if(cnt[i]==1) st=i;
	}
	dfs(st,0);
	for(int i=1;i<=n;i++){
		if(!vis[i]&&cnt[i]){
			printf("-1\n");
			return 0;
		}
	}
	int sz=ans.size();
	if(cnt[st]) sz--;
	printf("%d\n",sz);
	for(int i=0;i<sz;i++) printf("%d ",ans[i]);
}
