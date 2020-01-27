#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1000
#define maxm 100000
#define INF 0x3f3f3f3f
using namespace std;
struct edge{
	int from;
	int to;
	int next;
	int flow;
	int cost;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w,int c){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	E[sz].cost=c; 
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	E[sz].cost=-c; 
	head[v]=sz;
}

int dist[maxn+5];
int minf[maxn+5];
int pre[maxn+5];
bool inq[maxn+5];
bool spfa(int s,int t){
	memset(minf,0x3f,sizeof(minf));
	memset(dist,0x3f,sizeof(dist));
	memset(inq,0,sizeof(inq));
	memset(pre,0,sizeof(pre));
	queue<int>q;
	dist[s]=0;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow){
				if(dist[y]>dist[x]+E[i].cost){
					dist[y]=dist[x]+E[i].cost;
					pre[y]=i;
					minf[y]=min(minf[x],E[i].flow);
					if(!inq[y]){
						q.push(y);
						inq[y]=1;
					}
				}
			}
		}
	}
	return dist[t]!=INF;
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
int mcmf(int s,int t){
	int ans=0;
	while(spfa(s,t)){
		update(s,t);
		ans+=minf[t]*dist[t];
	}
	return ans;
}

int n,m;
int main(){
	int tim;
	scanf("%d %d",&m,&n);
	int s=0,t=n+n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&tim);
			for(int k=1;k<=n;k++) add_edge(i,j*n+k,1,tim*k);
			//是求总的等待时间，要先等前面的车修完，所以要按这辆车是这个工人修的倒数k辆车拆点,费用为tim*k 
			//修这辆车导致后面k辆车要等tim*k的时间 
		}
	}
	for(int i=1;i<=n;i++) add_edge(s,i,1,0);
	for(int i=1;i<=n*m;i++) add_edge(i+n,t,1,0);
	int sum=mcmf(s,t);
	printf("%.2f\n",1.0*sum/n);
}

