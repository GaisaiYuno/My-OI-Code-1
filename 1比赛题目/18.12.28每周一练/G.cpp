/*
Problem:ÇÀÂÓ¼Æ»®[APIO 2009]
Source:http://111.230.183.91/contest/14/problem/7
Algorithm:Tarjan
Description:
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define maxn 500005
using namespace std;
struct edge{
	int u;
	int v;
	edge(){
		
	}
	edge(int from,int to){
		u=from;
		v=to;
	}
	friend bool operator < (edge a,edge b){
		if(a.u==b.u) return a.v<b.v;
		else return a.u<b.u;
	}
};
map<edge,int>used;
int n,m,st,p;
vector<int>G[maxn];
vector<int>D[maxn];
int money[maxn];
int tim=0;
int cnt=0;
int dfn[maxn];
int low[maxn];
int ins[maxn];
int belong[maxn];
long long dp[maxn],val[maxn];
stack<int>s;
void tarjan(int x){
	s.push(x);
	ins[x]=1;
	dfn[x]=low[x]=++tim;
	int t=G[x].size();
	for(int i=0;i<t;i++){
		int y=G[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		int y;
		do{
			y=s.top();
			s.pop();
			ins[y]=0;
			val[cnt]+=money[y];
			belong[y]=cnt;
		}while(x!=y);
	}
}

int in[maxn];
int out[maxn];
void graph_to_dag(){
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		int t=G[i].size();
		for(int j=0;j<t;j++){
			int k=G[i][j];
			if(belong[i]!=belong[k]){
				if(used.count(edge(belong[i],belong[k]))) continue; 
				used[edge(belong[i],belong[k])]=1;
				D[belong[i]].push_back(belong[k]);
				in[belong[k]]++;
			}
		}
	}
}

int is_ok[maxn];
void topo_sort(int s){
	queue<int>q;
	is_ok[s]=1;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	dp[s]=val[s];
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int t=D[x].size();
		for(int i=0;i<t;i++){
			int y=D[x][i];
			in[y]--;
			if(is_ok[x]){
				dp[y]=max(dp[y],dp[x]+val[y]);
				is_ok[y]=1;
			}
			if(in[y]==0) q.push(y); 
		}
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&money[i]);
	}
	graph_to_dag();
	scanf("%d %d",&st,&p);
	topo_sort(belong[st]);
	long long ans=0;
	for(int i=1;i<=p;i++){
		scanf("%d",&u);
		ans=max(ans,dp[belong[u]]);
	}
	printf("%lld\n",ans);
}

