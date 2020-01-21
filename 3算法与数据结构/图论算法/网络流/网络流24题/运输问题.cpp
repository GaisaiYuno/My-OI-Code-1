/*
Problem:运输问题 
Source:https://www.luogu.org/problemnew/show/P4015
Description:
从S向仓库连边，容量a[i],费用0
仓库和商店之间连边，容量INF，费用c[i][j] 
商店向T连边，容量b[i],费用0 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 205
#define maxm 100005
#define INF 0x3f3f3f3f
using namespace std;
int m,n;
struct edge{
	int from;
	int to;
	int next;
	int flow;
	int cost;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w,int c){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	E[sz].cost=c; 
	head[u]=sz;
} 

int dist[maxn];
int minf[maxn];
int pre[maxn];
int inq[maxn]; 
bool spfa(int s,int t){
	memset(dist,0x3f,sizeof(dist));
	queue<int>q;
	q.push(s);
	inq[s]=1;
	dist[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0; 
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow){
				if(dist[y]>dist[x]+E[i].cost){
					dist[y]=dist[x]+E[i].cost;
					minf[y]=min(minf[x],E[i].flow);
					pre[y]=i;
					if(!inq[y]){
						inq[y]=1;
						q.push(y);
					} 
				}
			}
		}
	} 
	if(dist[t]==INF) return 0;
	else return 1;
}

void update(int s,int t){
	int x=t;
	while(x!=s){
		int i=pre[x];
		E[i].flow-=minf[t];
		E[i^1].flow+=minf[t];
		x=E[i^1].to;
	}
}

int EK(int s,int t){
	memset(minf,0x3f,sizeof(minf));
	int mincost=0;
	while(spfa(s,t)){
		update(s,t);
		mincost+=dist[t]*minf[t];
	}
	return mincost;
}

int a[maxn];
int b[maxn];
int c[maxn][maxn];
int main(){
	scanf("%d %d",&m,&n); 
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		} 
	} 
	int s=0,t=n+m+1;
	for(int i=1;i<=m;i++){
		add_edge(s,i,a[i],0);
		add_edge(i,s,0,0); 
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			add_edge(i,j+m,INF,c[i][j]);
			add_edge(j+m,i,0,-c[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		add_edge(i+m,t,b[i],0);
		add_edge(t,i+m,0,0);
	}
	printf("%d\n",EK(s,t));
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=1;
	for(int i=1;i<=m;i++){
		add_edge(s,i,a[i],0);
		add_edge(i,s,0,0); 
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			add_edge(i,j+m,INF,-c[i][j]);
			add_edge(j+m,i,0,c[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		add_edge(i+m,t,b[i],0);
		add_edge(t,i+m,0,0);
	}
	printf("%d\n",-EK(s,t));
}

