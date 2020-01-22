#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue>
#define maxn 1000
#define maxm 10000
#define INF 0x3f3f3f3f
using namespace std;
int n,m,a[maxn+5],b[maxn+5];

struct edge{
	int from;
	int to;
	int next;
	int flow;
}E[maxm*2+5];
int head[maxn*2+5];
int sz=1; 
void add_edge(int u,int v,int w){
#ifdef DEBUG
	printf("%d->%d %d\n",u,v,w);
#endif
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	head[v]=sz;
}
int deep[maxn+5];
bool bfs(int s,int t){
	memset(deep,0,sizeof(deep));
	queue<int>q;
	q.push(s);
	deep[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!deep[y]&&E[i].flow){
				deep[y]=deep[x]+1;
				q.push(y);
			}
		}
	}
	return deep[t]>0;
}
int dfs(int x,int t,int minf){
	if(x==t) return minf; 
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,E[i].flow));
			E[i].flow-=k;
			E[i^1].flow+=k;
			rest-=k;
			if(k==0) deep[y]=0;
			if(rest==0) break;
		}
	}
	return minf-rest;
}
int dinic(int s,int t){
	int ans=0,now;
	while(bfs(s,t)){
		while((now=dfs(s,t,INF))) ans+=now;
	}
	return ans;
}

int ans[maxn+5][maxn+5];
int main(){
	int suma=0,sumb=0;
	int u,v;
	scanf("%d %d",&n,&m);
	int s=0,t=n*2+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add_edge(s,i,a[i]);
		suma+=a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sumb+=b[i];
		add_edge(i+n,t,b[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v+n,INF);
		add_edge(v,u+n,INF);
	}
	for(int i=1;i<=n;i++) add_edge(i,i+n,INF);
	int maxflow=dinic(s,t);
	if(maxflow!=sumb||maxflow!=suma) printf("NO\n");
	else{
		printf("YES\n");
		for(int i=1;i<=n;i++){
			for(int j=head[i];j;j=E[j].next){
				ans[i][E[j].to-n]=E[j^1].flow;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}
}

