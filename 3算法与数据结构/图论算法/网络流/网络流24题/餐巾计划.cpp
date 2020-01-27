/*
Problem:餐巾计划问题
Source:https://www.luogu.org/problemnew/show/P1251
Description:
[copy]
首先，我们拆点，将一天拆成晚上和早上，每天晚上会受到脏餐巾（来源：当天早上用完的餐巾，在这道题中可理解为从原点获得），每天早上又有干净的餐巾（来源：购买、快洗店、慢洗店）。

1.从原点向每一天晚上连一条流量为当天所用餐巾x，费用为0的边，表示每天晚上从起点获得x条脏餐巾。

2.从每一天早上向汇点连一条流量为当天所用餐巾x，费用为0的边，每天白天,表示向汇点提供x条干净的餐巾,流满时表示第i天的餐巾够用 。 3.从每一天晚上向第二天晚上连一条流量为INF，费用为0的边，表示每天晚上可以将脏餐巾留到第二天晚上（注意不是早上，因为脏餐巾在早上不可以使用）。

4.从每一天晚上向这一天+快洗所用天数t1的那一天早上连一条流量为INF，费用为快洗所用钱数的边，表示每天晚上可以送去快洗部,在地i+t1天早上收到餐巾 。

5.同理，从每一天晚上向这一天+慢洗所用天数t2的那一天早上连一条流量为INF，费用为慢洗所用钱数的边，表示每天晚上可以送去慢洗部,在地i+t2天早上收到餐巾 。

6.从起点向每一天早上连一条流量为INF，费用为购买餐巾所用钱数的边，表示每天早上可以购买餐巾 。 注意，以上6点需要建反向边！3~6点需要做判断（即连向的边必须<=n）
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10005
#define maxm 500005
#define INF 0x3f3f3f3f3f3f3f3f  
using namespace std; 
int n; 

struct edge{
    int from;
    int to;
    int next;
    long long flow;
    long long cost;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,long long w,long long c){
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
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

long long dist[maxn];
long long minf[maxn];
int pre[maxn];
int inq[maxn]; 
bool spfa(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(inq));
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

long long mcmf(int s,int t){
    memset(minf,0x3f,sizeof(minf));
    long long mincost=0,maxflow=0;
    while(spfa(s,t)){
        update(s,t);
        mincost+=dist[t]*minf[t];
        maxflow+=minf[t];
    }
    return mincost;
}
int p,fcost,fday,scost,sday;
int r[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	scanf("%d %d %d %d %d",&p,&fday,&fcost,&sday,&scost);
	int s=0,t=n*2+1;
	for(int i=1;i<=n;i++){
		add_edge(s,i+n,r[i],0);
		add_edge(i,t,r[i],0);
	}
	for(int i=1;i<n;i++){
		add_edge(i+n,i+1+n,INF,0);
	}
	for(int i=1;i+fday<=n;i++){
		add_edge(i+n,i+fday,INF,fcost);
	}
	for(int i=1;i+sday<=n;i++){
		add_edge(i+n,i+sday,INF,scost);
	}
	for(int i=1;i<=n;i++){
		add_edge(s,i,INF,p);
	}
//	for(int i=n-min(fday,sday)+1;i<=n;i++){
//		add_edge(i+n,t,INF,0);
//	}
	printf("%lld\n",mcmf(s,t));
}
