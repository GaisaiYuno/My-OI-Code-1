#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 1005
#define maxv 1010
#define maxe 550005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std; 
struct edge{
	int from;
	int to;
	int next;
	long long flow;
}E[maxe];
int head[maxv];
int sz=1;
void add_edge(int u,int v,long long w){
//	printf("%d %d %lld\n",u,v,w);
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

int deep[maxn];
bool bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
			}
		}
	}
	return deep[t]!=0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long k,rest=minf;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(deep[y]==deep[x]+1&&E[i].flow){
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

long long dinic(int s,int t){
	long long ans=0,now=0;
	while(bfs(s,t)){
		while(now=dfs(s,t,INF)) ans+=now;
	}
	return ans;
}

int n,m;
int life[maxn*2];
int tab[maxn][maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&life[i]);
	for(int i=n+1;i<=n*2;i++) scanf("%d",&life[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&tab[i][j]);
		}
	}
	int s=0,s1=1,t=2*n+2;
	add_edge(s,s1,m);
	for(int i=1;i<=n;i++){
		add_edge(s,i+1,life[i]);
	}
	for(int i=n+1;i<=n*2;i++){
		add_edge(i+1,t,life[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(tab[i][j]==1){
				add_edge(i+1,i+n+1,1);
			}
		}
	}
	printf("%lld\n",dinic(s,t));
} 
