#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 105
#define maxm 100005
#define INF 0x7fffffff
using namespace std;
int T,n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
int flow[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	if(u<v)printf("%d->%d %d\n",u,v,w);
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
			if(k==0) deep[y]=0;
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

int count[maxn][maxn];
void ini(){
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=1;
	memset(flow,0,sizeof(flow));
	memset(count,0,sizeof(count));
}
int main(){
	int k,x;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		ini();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			for(int j=1;j<=k;j++){
				scanf("%d",&x);
				count[i][x]++;
			}
		}
		for(int i=1;i<=m;i++){
			add_edge(0,i,count[1][i]);
			add_edge(i,0,0);
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!count[i][j]){
					add_edge(j,i+m,1);
					add_edge(i+m,j,0);
				}else if(count[i][j]>=2){
					add_edge(i+m,j,count[i][j]-1);
					add_edge(j,i+m,0);
				}
			}
		}
		for(int i=1;i<=m;i++){
			add_edge(i,n+m+1,1);
			add_edge(n+m+1,i,0);
		}
		printf("Case #%d: %d\n",cas,dinic(0,n+m+1));
	}
}
