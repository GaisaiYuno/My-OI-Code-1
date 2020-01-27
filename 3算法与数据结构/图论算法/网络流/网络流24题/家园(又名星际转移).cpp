/*
Problem:星际转移「网络流 24 题」
Source:https://www.luogu.org/problemnew/show/P2754
Description:
按天分层
源点想每一天的地球连INF
每一天的月亮向汇点连INF
从上一天的每个太空站向当天的太空站连INF
对于飞船，从上一天到这一天连容量为飞船满载人数的流 

月球编号1，地球编号2，其他3~n+2
第i天编号为(i-1)*(n+2)+k 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm> 
#define maxc 105
#define maxn 10005
#define maxm 500005
#define INF 0x3f3f3f3f
using namespace std;
int n,m,k;
struct edge{
    int from;
    int to;
    int next;
    int flow;
}E[maxm<<1];
int sz=1;
int head[maxn]; 
void add_edge(int u,int v,int w){
//	printf("%d->%d %d\n",u,v,w); 
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].flow=w;
    E[sz].next=head[u];
    head[u]=sz;
    
    sz++;
    E[sz].from=v;
    E[sz].to=u;
    E[sz].flow=0;
    E[sz].next=head[v];
    head[v]=sz;
}

int deep[maxn];
bool bfs(int s,int t){
    queue<int>q;
    q.push(s);
    for(int i=s;i<=t;i++) deep[i]=0;
    deep[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(E[i].flow&&!deep[y]){
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
    int k,rest=minf;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(E[i].flow&&deep[y]==deep[x]+1){
            k=dfs(y,t,min(rest,E[i].flow));
            rest-=k;
            E[i].flow-=k;
            E[i^1].flow+=k;
            if(k==0) deep[y]=0;
            if(rest==0) break;
        }
    }
    return minf-rest;
}

int dinic(int s,int t){
    int nowflow=0,maxflow=0;
    while(bfs(s,t)){
        while(nowflow=dfs(s,t,INF)) maxflow+=nowflow;
    }
    return maxflow;
}

int man[maxc];
int scnt[maxc];
int stop[maxc][maxc];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	n+=2; 
	for(int i=1;i<=m;i++){
		scanf("%d %d",&man[i],&scnt[i]);
		for(int j=0;j<scnt[i];j++){
			scanf("%d",&stop[i][j]);
			stop[i][j]+=2;
		}
	}
	
	int s=0,t=501*n+3; 
	int ans=0;
	const int maxans=500;
	int sum=0;
	while(ans<maxans){
		add_edge(ans*n+1,t,INF);
		add_edge(s,ans*n+2,INF);
		if(ans!=0){
			for(int i=1;i<=n;i++){
				add_edge((ans-1)*n+i,ans*n+i,INF);
			}
			for(int i=1;i<=m;i++){
				int last=stop[i][(ans-1)%scnt[i]];
				int now=stop[i][ans%scnt[i]];
				add_edge((ans-1)*n+last,ans*n+now,man[i]);
			}
		}
		sum+=dinic(s,t);
		if(sum>=k) break;
		ans++;
	}
	if(ans==maxans) printf("0");
	else printf("%d",ans);
}


