#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100005
#define maxm 500005 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
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
	printf("%d->%d vol=%lld cost=%lld\n",u,v,w,c);
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
    memset(pre,0,sizeof(pre));
    long long mincost=0;
    while(spfa(s,t)){
        update(s,t);
        mincost+=dist[t]*minf[t];
    }
    return -mincost;
}

int aa,bb,n,m; 
inline int get_id(int x,int y){
	return (x-1)*m+y;
}
int main() {
	int x,y,w;
	scanf("%d %d %d %d",&aa,&bb,&n,&m);
	n++;
	m++;
	int s=0,t=n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&w);
			add_edge(get_id(i,j),get_id(i,j+1),1,w);
			add_edge(get_id(i,j),get_id(i,j+1),INF,0);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			scanf("%d",&w);
			add_edge(get_id(j,i),get_id(j+1,i),1,w);
			add_edge(get_id(j,i),get_id(j+1,i),INF,0);
		}
	}
	for(int i=1;i<=aa;i++){
		scanf("%d %d %d",&w,&x,&y);
		x++;
		y++;
		add_edge(s,get_id(x,y),w,0); 
	}
	for(int i=1;i<=bb;i++){
		scanf("%d %d %d",&w,&x,&y);
		x++;
		y++;
		add_edge(get_id(x,y),t,w,0); 
	}
	printf("%lld\n",mcmf(s,t));
}

