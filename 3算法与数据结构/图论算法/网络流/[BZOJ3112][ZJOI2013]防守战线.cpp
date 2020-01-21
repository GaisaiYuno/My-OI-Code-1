#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 10000
#define maxm 200000
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x){
    x=0;
    int sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x=x*sign;
}
struct edge{
	int from;
	int to;
	int next;
	int flow;
	int cost;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w,int c){
//	printf("%d->%d flow=%d cost=%d\n",u,v,w,c);
	c=-c;//转化成对偶问题，变成最大费用 
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

int dist[maxn+5];
int minf[maxn+5];
int pre[maxn+5];
bool inq[maxn+5];
bool spfa(int s,int t){
	for(int i=s;i<=t;i++){
		minf[i]=dist[i]=INF;
		inq[i]=0;
		pre[i]=0;
	}
	queue<int>q;
	dist[s]=0;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow){
				if(dist[y]>dist[x]+E[i].cost){
					dist[y]=dist[x]+E[i].cost;
					pre[y]=i;
					minf[y]=min(minf[x],E[i].flow);
					if(!inq[y]){
						q.push(y);
						inq[y]=1;
					}
				}
			}
		}
	}
	return dist[t]!=INF;
}

bool vis[maxn+5];
int dfs(int x,int t,int minf,int &cost){
	if(x==t){
		cost+=dist[t]*minf;
		return minf;
	}
	int rest=minf,k;
	vis[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(vis[y]) continue;
		if(E[i].flow&&dist[y]==dist[x]+E[i].cost){
			k=dfs(y,t,min(rest,E[i].flow),cost);
			E[i].flow-=k;
			E[i^1].flow+=k;
			rest-=k;
			if(k==0) dist[y]=INF;
			if(rest==0) break;
		}
	}
	vis[x]=0;
	return minf-rest;
}
int mcmf(int s,int t){
	int flow=0,cost=0;
	int now;
	while(spfa(s,t)){
		while((now=dfs(s,t,INF,cost))) flow+=now;
	}
	return -cost;
}

int n,m;
int a[maxn+5];
int main(){
	int u,v,w;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);		
	}
	for(int i=1;i<=m;i++){
		qread(u);
		qread(v);
		qread(w);
		add_edge(u,v+1,INF,w); 
	}
	int s=0,t=n+2;
	for(int i=1;i<=n+1;i++){
		int c=a[i]-a[i-1];
		if(c>=0){
			add_edge(s,i,c,0);
		}else{
			add_edge(i,t,-c,0);
		}
	}
	for(int i=1;i<=n;i++) add_edge(i,i+1,INF,0);
	printf("%d\n",mcmf(s,t));
}
