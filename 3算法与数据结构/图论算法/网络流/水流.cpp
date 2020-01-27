/*
Problem:Ë®Á÷ 
Source:http://111.230.183.91/problem/3033
Description: 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 105
#define maxm 1405
#define INF 0x7fffffff
using namespace std;
int n,m;
int get_id(char c){
	if(c>='a'&&c<='z') return 27+c-'a';
	else return c-'A'+1;
} 

struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int sz=1;
int flow[maxm];
int d[maxn];
void add_edge(int u,int v,int w){
//	printf("(%d,%d)->%d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

queue<int>q;
int bfs(int s,int t){
	while(!q.empty()) q.pop();
	q.push(s);
	memset(d,0,sizeof(d));
	d[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(flow[i]&&!d[y]){
				d[y]=d[x]+1;
				q.push(y);
				if(y==t) return 1;
			}
		}
	}
	return 0;
}

int dfs(int x,int t,long long minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&d[y]==d[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int maxflow=0;
	int fl=0;
	while(bfs(s,t)){
		while(fl=dfs(s,t,INF)) maxflow+=fl;
	}
	return maxflow;
}

int main(){
	char x[2],y[2];
	int u,v,w;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s %s %d",x,y,&w);
		u=get_id(x[0]);
		v=get_id(y[0]);
		n=max(n,max(u,v));
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	printf("%d\n",dinic(get_id('A'),get_id('Z')));
}
