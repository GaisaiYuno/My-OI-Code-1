/*
Problem:
Source:
Description
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 105
#define maxm 1000005
#define maxn 1000005
#define INF 1e10
using namespace std;
int n,m;
double wen0[maxc][maxc];
double wen[maxc][maxc];
double li[maxc][maxc];//共同 
double li0[maxc][maxc];//自己 
inline int get_id(int x,int y){
	return (x-1)*m+n;
}

struct edge{
    int from;
    int to;
    int next;
}E[maxm<<1];
double flow[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,double w){
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    flow[sz]=w;
    head[u]=sz;
    
    sz++;
    E[sz].from=v;
    E[sz].to=u;
    E[sz].next=head[v];
    flow[sz]=w;
    head[v]=sz;
}

int deep[maxn];
queue<int>q;
int bfs(int s,int t){
    while(!q.empty()) q.pop();
    q.push(s);
    memset(deep,0,sizeof(deep));
    deep[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(flow[i]&&!deep[y]){
                deep[y]=deep[x]+1;
                q.push(y);
                if(y==t) return 1;
            }
        }
    }
    return 0;
}

double dfs(int x,int t,double minf){
    if(x==t) return minf;
    double rest=minf,k;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(flow[i]&&deep[y]==deep[x]+1){
            k=dfs(y,t,min(rest,flow[i]));
            flow[i]-=k;
            flow[i^1]+=k;
            rest-=k;
        }
    }
    return minf-rest;
}

double dinic(int s,int t){
    double maxflow=0,nowflow=0;
    while(bfs(s,t)){
        while(nowflow=dfs(s,t,INF)) maxflow+=nowflow; 
    }
    return maxflow;
}

int main(){
	int s,t;
	double x;
	double sum=0;
	scanf("%d %d",&n,&m);
	s=0;
	t=n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&wen0[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&li0[i][j]);
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&x);
			wen[i][j]+=x/2;
			wen[i+1][j]+=x/2;
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&x);
			li[i][j]+=x/2;
			li[i+1][j]+=x/2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%lf",&x);
			wen[i][j]+=x/2;
			wen[i][j+1]+=x/2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%lf",&x);
			li[i][j]+=x/2;
			li[i][j+1]+=x/2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add_edge(s,get_id(i,j),wen0[i][j]+wen[i][j]);
			add_edge(get_id(i,j),t,li0[i][j]+li[i][j]);
			sum+=wen0[i][j]+wen[i][j];
			sum+=li0[i][j]+li[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j+1<=m){
				add_edge(get_id(i,j),get_id(i,j+1),(li[i][j]+li[i][j+1]+wen[i][j]+wen[i][j+1])/2);
			}
			if(i+1<=n){
				add_edge(get_id(i,j),get_id(i+1,j),(li[i][j]+li[i+1][j]+wen[i][j]+wen[i+1][j])/2);
			}
		}
	}
	printf("%d",int(sum-dinic(s,t)));
} 
