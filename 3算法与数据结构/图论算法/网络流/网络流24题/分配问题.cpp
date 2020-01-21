/*
Problem:分配问题
Source:https://www.luogu.org/problemnew/show/P4014
Description:
二分图带权匹配
费用流，费用为边权 
其他的和最大流求二分图匹配一样 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 205
#define maxm 100005 
#define INF 0x3f3f3f3f
using namespace std;
int n;
struct edge {
    int from;
    int to;
    int next;
    int flow;
    int cost;
} E[maxm<<1];
int sz=1;
int head[maxn];
int pre[maxn];
int minf[maxn];
int dist[maxn];
int inq[maxn];
void add_edge(int u,int v,int w,int c) {
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].flow=w;
    E[sz].cost=c;
    E[sz].next=head[u];
    head[u]=sz;
}

int spfa(int s,int t){
    queue<int>q;
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(q));
    q.push(s);
    dist[s]=0;
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
		mincost+=minf[t]*dist[t];
	}
	return mincost;
}

int tmp[maxn][maxn];
int main(){
	int x;
	scanf("%d",&n);
	int s=0,t=2*n+1;
	for(int i=1;i<=n;i++){
		add_edge(s,i,1,0);
		add_edge(i,s,0,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			tmp[i][j]=x;
			add_edge(i,j+n,1,x);
			add_edge(j+n,i,0,-x);
		}
	}
	for(int i=1;i<=n;i++){
		add_edge(i+n,t,1,0);
		add_edge(t,i+n,0,0);
	}
	printf("%d\n",EK(s,t));
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=1;
	for(int i=1;i<=n;i++){
		add_edge(s,i,1,0);
		add_edge(i,s,0,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			add_edge(i,j+n,1,-tmp[i][j]);
			add_edge(j+n,i,0,tmp[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		add_edge(i+n,t,1,0);
		add_edge(t,i+n,0,0);
	}
	printf("%d\n",-EK(s,t));
} 

