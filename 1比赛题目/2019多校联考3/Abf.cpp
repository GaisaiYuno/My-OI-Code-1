#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>
#include<queue> 
#define INF 0x3f3f3f3f
#define maxn 1000
#define maxm 100000
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1; 
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz; 
} 


struct node{
	int x;
	int d;
	node(){
		
	}
	node(int _x,int _d){
		x=_x;
		d=_d;
	}
	friend bool operator < (node p,node q){
		return p.d>q.d;
	}
};
priority_queue<node>q;
int dist[maxn+5];
int vis[maxn+5];
pair<int,int>tmp[maxn+5]; 
int du,dv;
void dijkstra(int s){
	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		int x=q.top().x;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(x==du&&y==dv) continue;
			if(dist[y]>dist[x]+1){
				dist[y]=dist[x]+1;
				q.push(node(y,dist[y]));
			} 
		}
	}
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
//		add_edge(v,u);
		tmp[i]=make_pair(u,v);
	}
	for(int i=1;i<=m;i++){
		du=tmp[i].first;
		dv=tmp[i].second;
		dijkstra(du);
		if(dist[dv]==INF) printf("-1 ");
		else printf("%d ",dist[dv]);
	}
}

