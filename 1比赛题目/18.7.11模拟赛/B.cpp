#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100005
using namespace std;
//int d[maxn],p[maxn];
int used[maxn];
vector<int>E[maxn];
double ans=0;
int n;
void dfs(int x,int de,double po){
	used[x]=1;
	if(E[x].size()==1&&x!=1){
		ans+=de*po;
		return;
	}
	int cnt=0;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i]; 
		if(!used[y]){
			cnt++;
		}
	}
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(!used[y]){
			dfs(y,de+1,po*1/cnt);
		}
	}
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if(n!=1)dfs(1,0,1);
	printf("%.15f",ans);
}

