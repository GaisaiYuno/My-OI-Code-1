/*
Problem:happiness[集训队论文2016]
Source:http://119.29.55.79/problem/169
Description:
Dinic模板里不要memset,否则会被卡
改成for循环- 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 205
#define maxm 300005
#define maxn 300005
#define INF 1e10
using namespace std;
int n,m;
double wen[maxc][maxc];
double li[maxc][maxc]; 
inline int get_id(int x,int y){
	return (x-1)*m+y;
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
    for(int i=0;i<=n*m+1;i++) deep[i]=0;
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
            if(k==0) deep[y]=0;
            flow[i]-=k;
            flow[i^1]+=k;
            rest-=k;
            if(rest==0) return minf;
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
#ifdef INPUT_FILE
	freopen("input.txt","r",stdin);
#endif
	int s,t;
	double x;
	double sum=0;
	scanf("%d %d",&n,&m);
	s=0;
	t=n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&wen[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&li[i][j]);
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&x);
			wen[i][j]+=x/2;
			wen[i+1][j]+=x/2;
			add_edge(get_id(i,j),get_id(i+1,j),x/2);
		}
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%lf",&x);
			li[i][j]+=x/2;
			li[i+1][j]+=x/2;
			add_edge(get_id(i,j),get_id(i+1,j),x/2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%lf",&x);
			wen[i][j]+=x/2;
			wen[i][j+1]+=x/2;
			add_edge(get_id(i,j),get_id(i,j+1),x/2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%lf",&x);
			li[i][j]+=x/2;
			li[i][j+1]+=x/2;
			add_edge(get_id(i,j),get_id(i,j+1),x/2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add_edge(s,get_id(i,j),wen[i][j]);
			add_edge(get_id(i,j),t,li[i][j]);
			sum+=wen[i][j];
			sum+=li[i][j];
		}
	}
	printf("%d",int(sum-dinic(s,t)));
}
