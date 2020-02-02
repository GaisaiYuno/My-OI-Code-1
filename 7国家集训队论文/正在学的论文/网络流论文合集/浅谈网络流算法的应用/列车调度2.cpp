//http://codevs.cn/problem/1035/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxm 105
#define maxv 305
#define maxe 10005
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int cost[maxm];
int stay[maxm];
int reach[maxm];

struct edge{
	int from;
	int to;
	int next;
	int flow;
	double cost;
}E[maxe<<1];
int head[maxv];
int sz=1;
void add_edge(int u,int v,int w,double c){
//	printf("%d->%d vol=%d cost=%.2f\n",u,v,w,c);
	c=-c;
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].flow=w;
	E[sz].cost=c;
	E[sz].next=head[u];
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].flow=0;
	E[sz].cost=-c;
	E[sz].next=head[v];
	head[v]=sz;
} 

int minf[maxv];
int pre[maxv];
int inq[maxv];
double dist[maxv];
bool spfa(int s,int t){
	for(int i=s;i<=t;i++){
		dist[i]=INF;
		inq[i]=0;
	}
	dist[s]=0;
	queue<int>q;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].cost&&E[i].flow){
				minf[y]=min(minf[x],E[i].flow);
				pre[y]=i;
				dist[y]=dist[x]+E[i].cost;
				if(!inq[y]){
					q.push(y);
					inq[y]=1;
				}
			}
		}
	} 
	if(dist[t]!=INF) return 1;
	else return 0;
}
void update(int s,int t){
	int x=t;
	while(x!=s){
		int i=pre[x];
		E[i].flow-=minf[t];
		E[i^1].flow+=minf[t];
		x=E[i].from;
	}
}
double mcmf(int s,int t){
	memset(minf,0x3f,sizeof(minf));
	double ans=0;
	int cnt=0;
	while(spfa(s,t)&&cnt<n){
		ans+=minf[t]*dist[t];
		update(s,t);
		cnt++;
	}
	return -ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&reach[i],&cost[i],&stay[i]);
	} 
	int s1=1,t=1+m*2+1;
	for(int i=1;i<=m;i++){
		add_edge(s1,i+1,1,0);
		add_edge(i+1,i+1+m,1,cost[i]*0.01);
		add_edge(i+1+m,t,1,0);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(reach[i]+stay[i]<reach[j]){
				add_edge(i+1+m,j+1,1,0);
			}
		}
	}
	printf("%.2lf\n",mcmf(s1,t)); 
}
