#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 2005 
using namespace std;
int C,n,m;
vector<int>E[maxn];
int v[maxn];
bool flag=true;
void dfs(int x,int color){
	v[x]=color;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(!v[y]){
			dfs(y,3-color);
		}else if(v[y]==color){
			flag=false;
		}
	}
}

void ini(){
	flag=true;
	for(int i=1;i<=n;i++){
		E[i].clear();
		v[i]=0;
	}
}

int main(){
	int s,t;
	scanf("%d",&C);
	for(int cas=1;cas<=C;cas++){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&s,&t);
			E[s].push_back(t);
			E[t].push_back(s);
		}
		for(int i=1;i<=n;i++){
			if(!v[i]){
				dfs(i,1);
				if(!flag) break;
			}
		}
		if(flag){
			printf("Scenario #%d:\nNo suspicious bugs found!\n\n",cas);
		}else{
			printf("Scenario #%d:\nSuspicious bugs found!\n\n",cas);
		}
	}
}
