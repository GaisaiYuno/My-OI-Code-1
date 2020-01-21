/*
Problem:吃饭[集训队论文2016]
Source:http://111.230.183.91/problem/163
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 505
#define maxm 100005 
#define INF 0x7fffffff
#define FOOD 1
#define DRINK 2
#define COW 3
using namespace std;
int n,f,d;
int get_id(int x,int type){
	if(type==FOOD) return x;
	else if(type==COW) return f+x;
	else if(type==DRINK) return f+n+x;
}

struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
int flow[maxm];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	if(u<v) printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

int deep[maxn];
int bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(flow[i]&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
				if(y==t) return 1;
			} 
		}
	}
	return 0;
}

int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			if(k==0) deep[y]=0;
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int maxflow,nowflow;
	maxflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)){
			maxflow+=nowflow;
		}
	}
	return maxflow;
}

int main(){
	int nf,nd,x,y;
	scanf("%d %d %d",&n,&f,&d);
	for(int i=1;i<=f;i++){
		add_edge(0,get_id(i,FOOD),1);
		add_edge(get_id(i,FOOD),0,0);
	} 
	for(int i=1;i<=d;i++){
		add_edge(get_id(i,DRINK),n+f+d+1,1);
		add_edge(n+f+d+1,get_id(i,DRINK),0);
	} 
	for(int i=1;i<=n;i++){
		scanf("%d %d",&nf,&nd);
		for(int j=1;j<=nf;j++){
			scanf("%d",&x);
			add_edge(get_id(x,FOOD),get_id(i,COW),1);
			add_edge(get_id(i,COW),get_id(x,FOOD),0);
		}
		for(int j=1;j<=nd;j++){
			scanf("%d",&y);
			add_edge(get_id(i,COW),get_id(y,DRINK),1);
			add_edge(get_id(y,DRINK),get_id(i,COW),0);
		}
	}
	printf("%d\n",dinic(0,d+f+n+1));
}

