/*
Problem:[NOI2006]最大获利
Source:https://www.luogu.org/problemnew/show/P4174
Description:
最大权闭合子图
如果用户i需要中转站j，就在原图上连边(j,i)
i的点权-c[i],j的点权p[j]
然后跑模板即可 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
#define maxm 1000005
#define INF 0x7fffffff
using namespace std;
int n,m;
struct edge{
    int from;
    int to;
    int next;
}E[maxm<<1];
int flow[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    flow[sz]=w;
    head[u]=sz;
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

int dfs(int x,int t,int minf){
    if(x==t) return minf;
    int rest=minf,k;
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

int dinic(int s,int t){
    int maxflow=0,nowflow=0;
    while(bfs(s,t)){
        while(nowflow=dfs(s,t,INF)) maxflow+=nowflow; 
    }
    return maxflow;
}

int main(){
    int u,v,w;
   	scanf("%d %d",&n,&m);
   	for(int i=1;i<=n;i++){
   		scanf("%d",&w);
   		add_edge(0,i,w);
   		add_edge(i,0,0);
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(i+n,m+n+1,w);
		add_edge(m+n+1,i+n,0);
		add_edge(u,i+n,INF);
		add_edge(i+n,u,0);
		add_edge(v,i+n,INF);
		add_edge(i+n,v,0);
		sum+=w;
	}
	printf("%d\n",sum-dinic(0,m+n+1));
}
