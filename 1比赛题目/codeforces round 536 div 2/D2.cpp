#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define maxn 100005
using namespace std;
int n,m;
int vis[maxn];
vector<int>E[maxn];
vector<int>seq;
priority_queue<int,vector<int>,greater<int>>q;
void bfs(int s){
	q.push(s);
	while(!q.empty()){
		int x=q.top();
		q.pop();
		seq.push_back(x);
		vis[x]=1;
		for(auto y : E[x]){
			if(!vis[y]){
				vis[y]=1;
				q.push(y);
			}
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
	bfs(1);
	for(auto x : seq){
		printf("%d ",x);
	}
}

