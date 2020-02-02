#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10005
#define maxm 500005
#define INF 0x3f3f3f3f 
using namespace std; 
int n; 
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

int dist[maxn];
int minf[maxn];
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

int mcmf(int s,int t){
    memset(minf,0x3f,sizeof(minf));
    int mincost=0,maxflow=0;
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
	scanf("%d %d %d %d %d",&p,&fday,&fcost,&sday,&scost);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	int s=0,t=n*2+1;
	for(int i=1;i<=n;i++){
		add_edge(s,i,r[i],0);
		add_edge(i+n,t,r[i],0);
	}
	for(int i=1;i<n;i++){
		add_edge(i,i+1,INF,0);
	}
	for(int i=1;i+fday<=n;i++){
		add_edge(i,i+fday+n,INF,fcost);
	}
	for(int i=1;i+sday<=n;i++){
		add_edge(i,i+sday+n,INF,scost);
	}
	for(int i=1;i<=n;i++){
		add_edge(s,i+n,INF,p);
	}
	printf("%d\n",mcmf(s,t));
}
