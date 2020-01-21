#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100005
#define maxm 500005 
#define INF 0x3f3f3f3f3f3f3f3f
#define maxc 55
using namespace std;
int m,n;
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
//	printf("%d->%d vol=%lld cost=%lld\n",u,v,w,c);
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
int a[maxc][maxc];
int num[maxc];
int id[maxc][maxc];
void ini(){
	memset(E,0,sizeof(E));
	sz=1;
	memset(head,0,sizeof(head));
}

int tot=0;
long long solve(int type){
	int s,t;
	ini();
	if(type==1){
		s=0,t=tot*2+1;
		for(int i=1;i<=num[1];i++){
			add_edge(s,id[1][i],1,0);
		}
		for(int i=1;i<=tot;i++) add_edge(i,i+tot,1,0);
		for(int i=1;i<n;i++){
			for(int j=1;j<=num[i];j++){
				add_edge(id[i][j]+tot,id[i+1][j],1,a[i][j]);
				add_edge(id[i][j]+tot,id[i+1][j+1],1,a[i][j]);
			}
		}
		for(int i=1;i<=num[n];i++){
			add_edge(id[n][i]+tot,t,1,a[n][i]); 
		}
		return mcmf(s,t);
	}else if(type==2){
		s=0,t=tot+1;
		for(int i=1;i<=num[1];i++){
			add_edge(s,id[1][i],1,0);
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=num[i];j++){
				add_edge(id[i][j],id[i+1][j],1,a[i][j]);
				add_edge(id[i][j],id[i+1][j+1],1,a[i][j]);
			}
		}
		for(int i=1;i<=num[n];i++){
			add_edge(id[n][i],t,INF,a[n][i]); 
		}
		return mcmf(s,t);
	}else{
		s=0,t=tot+1;
		for(int i=1;i<=num[1];i++){
			add_edge(s,id[1][i],1,0);
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=num[i];j++){
				add_edge(id[i][j],id[i+1][j],INF,a[i][j]);
				add_edge(id[i][j],id[i+1][j+1],INF,a[i][j]);
			}
		}
		for(int i=1;i<=num[n];i++){
			add_edge(id[n][i],t,INF,a[n][i]); 
		}
		return mcmf(s,t);
	}
}
int main() {
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		num[i]=m+i-1;
		for(int j=1;j<=num[i];j++){
			scanf("%d",&a[i][j]);
			id[i][j]=++tot;
		}
	} 
	for(int i=1;i<=3;i++) printf("%lld\n",solve(i));
}

