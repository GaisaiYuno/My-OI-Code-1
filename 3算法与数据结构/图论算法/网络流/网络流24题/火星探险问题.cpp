#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#include<vector> 
#define maxn 10005
#define maxm 100005 
#define maxc 105
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int flow;
	int cost;
}E[maxm<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v,int w,int c){
	c=-c;
//	printf("(%d,%d) vol=%d cost=%d\n",u,v,w,c);
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

int minf[maxn];
int inq[maxn];
int dist[maxn];
int pre[maxn];
bool spfa(int s,int t){
	queue<int>q;
	memset(dist,0x3f,sizeof(dist));
	memset(inq,0,sizeof(inq));
	q.push(s);
	dist[s]=0;
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].cost&&E[i].flow){
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
	if(dist[t]==INF) return 0;
	else return 1;
}

void update(int s,int t){
	int x=t;
	while(x!=s){
		int i=pre[x];
		E[i].flow-=minf[t];
		E[i^1].flow+=minf[t];
		x=E[i].from;
	}
}

int mcmf(int s,int t){
	memset(minf,0x3f,sizeof(minf));
	int cost=0;
	int flow=0;
	while(spfa(s,t)){
		update(s,t);
		cost+=minf[t]*dist[t];
		flow+=minf[t];
	}
//	return -ans;
	return flow;
}

inline int get_id(int x,int y){
	return (x-1)*m+y;
}

int num;
int a[maxc][maxc];
vector<int>ans;

void dfs(int x,int y){
	int now=get_id(x,y);
	for(int i=head[now+n*m];i;i=E[i].next){
		if(E[i^1].flow>0){
			E[i^1].flow--;
			if(E[i].to==get_id(x+1,y)){
				ans.push_back(0);
				dfs(x+1,y);
				return;
			}
			if(E[i].to==get_id(x,y+1)){
				ans.push_back(1);
				dfs(x,y+1);
				return;
			}
		}
	}
}
int main(){ 
	scanf("%d",&num);
	scanf("%d %d",&m,&n);
	int tot=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add_edge(get_id(i,j),get_id(i,j)+tot,INF,0);
			if(a[i][j]==2) add_edge(get_id(i,j),get_id(i,j)+tot,1,1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i+1<=n&&a[i+1][j]!=1){
				add_edge(get_id(i,j)+tot,get_id(i+1,j),INF,0);
			}
			if(j+1<=m&&a[i][j+1]!=1){
				add_edge(get_id(i,j)+tot,get_id(i,j+1),INF,0);
			}
		}
	}
	int s=0,t=tot*2+1;
	add_edge(s,get_id(1,1),num,0);
	add_edge(get_id(n,m)+tot,t,num,0);
	int flow=mcmf(s,t);
	for(int i=1;i<=flow;i++){
		ans.clear();
		dfs(1,1);
		for(int j=0;j<ans.size();j++){
			printf("%d %d\n",i,ans[j]);
		} 
	} 
}

