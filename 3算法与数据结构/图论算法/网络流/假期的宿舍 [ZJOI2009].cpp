/*
Problem:假期的宿舍 
Source:http://111.230.183.91/problem/110
Description:Dinic求二分图匹配 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 205
#define maxm 40005
#define INF 0x3f3f3f3f
using namespace std;
int is_sch[maxn];
int is_home[maxn];
int is_know[maxn][maxn];

int n,t;
/*
struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int flow[maxm];
int d[maxn];
int sz=1;
void add_edge(int u,int v,int w){
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

int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(d[y]==d[x]+1&&flow[i]){
			k=dfs(y,t,min(rest,flow[i]));
			rest-=k;
			flow[i]-=k;
			flow[i^1]+=k;
		}
	}
	return minf-rest;
} 

int dinic(int s,int t){
	int maxflow,fl;
	maxflow=0;
	while(bfs(s,t)){
		while(fl=dfs(s,t,INF)) maxflow+=fl;
	}
	return maxflow;
}*/
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

void ini(){
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=1;
	memset(flow,0,sizeof(flow));
}
int main(){
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		ini();
		for(int i=1;i<=n;i++) scanf("%d",&is_sch[i]);
		for(int i=1;i<=n;i++) scanf("%d",&is_home[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&is_know[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			if(is_sch[i]&&!is_home[i]){
				add_edge(i,i+n,1);
				add_edge(i+n,i,0);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(is_know[i][j]&&is_sch[j]){
					add_edge(i,j+n,1);
					add_edge(j+n,i,0); 
				}
			}
		}
		for(int i=1;i<=n;i++){
			add_edge(0,i,1);
			add_edge(i,0,0);
		}
		for(int i=n+1;i<=2*n;i++){
			add_edge(i,2*n+1,1);
			add_edge(2*n+1,i,0);
		}
		int requst=0;
		for(int i=1;i<=n;i++){
			if(!is_sch[i]||(is_sch[i]&&!is_home[i])) requst++;
		}
		if(dinic(0,2*n+1)==requst){
			printf("^_^\n");
		}else{
			printf("T_T\n");
		}
	}	
} 

