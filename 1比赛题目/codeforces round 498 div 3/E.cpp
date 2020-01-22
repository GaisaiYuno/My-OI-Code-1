#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 200005
using namespace std;
int n,q;
vector<int>E[maxn];
int cnt[maxn],used[maxn];
int seq[maxn],pos[maxn];
int ptr=0;
void dfs(int x){
	seq[++ptr]=x;
	pos[x]=ptr;
	used[x]=1;
	cnt[x]=1;
	int t=E[x].size();
	for(int i=0;i<t;i++){
		int y=E[x][i];
		if(!used[y]){
			dfs(y);
			cnt[x]+=cnt[y];
		} 
	}
}
int main(){
	scanf("%d %d",&n,&q);
	int p;
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		E[i].push_back(p);
		E[p].push_back(i);
	}
	for(int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
	}
	dfs(1);
	int u,k;
	while(q--){
		scanf("%d %d",&u,&k);
		if(k>cnt[u]) printf("-1\n");
		else printf("%d\n",seq[pos[u]+k-1]);
	}
}
