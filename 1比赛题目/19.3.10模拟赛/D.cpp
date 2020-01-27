#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 105
#define maxn 100005
#define maxm 2000005
#define INF 0x3f3f3f3f
using namespace std;
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
	c=-c;
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
    return -mincost;
}

int n,m;
int a[maxc][maxc];
const int dirx[4]={-1,1,0,0},diry[4]={0,0,-1,1};
inline int get_id(int x,int y){
	return m*(x-1)+y;
} 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int s=0,t=n*m*2+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add_edge(get_id(i,j),get_id(i,j)+n*m,1,0);
			if(a[i][j]<0) add_edge(s,get_id(i,j),1,0);
			if(a[i][j]>0) add_edge(get_id(i,j)+n*m,t,1,a[i][j]);
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<0){
				int k=-a[i][j]-1;
				for(int x=i,y=j;x>0&&x<=n&&y>0&&y<=m;x+=dirx[k],y+=diry[k]){
					if(x+dirx[k]>0&&x+dirx[k]<=n&&y+diry[k]>0&&y+diry[k]<=m){
						add_edge(get_id(x,y)+n*m,get_id(x+dirx[k],y+diry[k]),1,0);
					}
				}
			}
		}
	}
	printf("%d\n",mcmf(s,t));
}

