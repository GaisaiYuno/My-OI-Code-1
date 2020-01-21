/*
Problem:剪刀石头布[Wc2007&&集训队论文2016]
Source:http://119.29.55.79/problem/173
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 105
#define maxn 20005
#define maxm 50005
#define INF 0x3f3f3f3f 
using namespace std;
int n;
int graph[maxc][maxc];
int out[maxc];
struct edge {
    int from;
    int to;
    int next;
    int flow;
    int cost;
    void debug(){
    	printf("%d->%d vol=%d cost=%d\n",from,to,flow,cost);
	}
} E[maxm<<1];
int sz=1;
int head[maxn];
int pre[maxn];
int minf[maxn];
int dist[maxn];
int inq[maxn];
void add_edge(int u,int v,int w,int c) {
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
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

int mcmf(int s,int t){
	memset(minf,0x3f,sizeof(minf));
	int ans=0;
	while(spfa(s,t)){
		update(s,t);
		ans+=dist[t]*minf[t];
	}
	return ans;
}

inline int get_id(int x,int y){
	return (x-1)*n+y;
}

int res[maxc][maxc];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j]<2){
				out[i]+=graph[i][j];
			}
		}
	}	
	int s=0,t=n*n+n+1;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=(out[i]-1)*out[i]/2;
		for(int j=0;j<=n-1;j++){
			add_edge(n*n+i,t,1,out[i]+j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(graph[i][j]==2){
				add_edge(s,get_id(i,j),1,0);
				add_edge(get_id(i,j),n*n+i,1,0);
				add_edge(get_id(i,j),n*n+j,1,0);
			}
		}
	}
	
	printf("%d\n",n*(n-1)*(n-2)/6-mcmf(s,t)-sum);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			res[i][j]=graph[i][j];
		}
	}
	for(int i=2;i<=sz;i++){
		if(E[i].flow==0&&E[i].from>=1&&E[i].from<=n*n&&E[i].to>=1&&E[i].to<=n*n+n){
			E[i].debug();
			int tmp=E[i].from;
			int x=(tmp-1)/n+1,y=tmp-(x-1)*n;
			if(E[i].to==n*n+y) swap(x,y);
			res[x][y]=1;
			res[y][x]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}

