#include<iostream>
#include<cstdio>
#include<vector>
#define maxn 50005
using namespace std;
int n,m;
vector<int>ans[maxn];
int main() {
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		ans[i].push_back(i);
	for(int i=1;i<=m;i++) {
		scanf("%d %d",&u,&v);
		ans[u].push_back(u*10000+v);
		ans[v].push_back(u*10000+v);
	}
	for(int i=1;i<=n;i++) {
		int t=ans[i].size();
		printf("%d\n",t);
		for(int j=0;j<t;j++) printf("%d %d\n",i,ans[i][j]);
	}
}
