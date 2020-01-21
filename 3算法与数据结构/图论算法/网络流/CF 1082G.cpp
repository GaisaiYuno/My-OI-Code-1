/*
Problem:CF 1082G
Source:http://codeforces.com/contest/1082/problem/G
Description:
最大权闭合子图改版
权值=边权和-点权和
将边和点都看成新图中的点
S向原来的边i连边,权值为边权
点i向T连边，权值为点权
边i:(u,v,w)向u,v,连边，权值INF
ans=总边权-最小割 
*/
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue>
#define maxn 10005
#define maxm 10005
#define INF 0x3f3f3f3f3f3f3f3f 
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	long long flow;
}E[maxm<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v,long long w){
//	printf("%d->%d : %d\n",u,v,w);
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
	q.push(s);
	deep[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				if(y==t) return 1;
				q.push(y);
			} 
		}
	}
	return 0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long k,rest=minf;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,E[i].flow));
			if(k==0) deep[y]=0;
			E[i].flow-=k;
			E[i^1].flow+=k;
			rest-=k; 
			if(rest==0) break;
		}
	}
	return minf-rest;
}

long long dinic(int s,int t){
	long long maxflow=0,nowflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)) maxflow+=nowflow;
	}
	return maxflow;
}

int a[maxn];
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	int s=0,t=n+m+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add_edge(i,t,a[i]);
	}
	long long sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		sum+=w;
		add_edge(s,i+n,w);
		add_edge(i+n,u,INF);
		add_edge(i+n,v,INF);
	}
	printf("%I64d\n",sum-dinic(s,t));
}


