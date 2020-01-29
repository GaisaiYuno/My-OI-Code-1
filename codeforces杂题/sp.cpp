#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<queue>
#define maxn 1000
#define maxm 10000
#define mod 1000000007
using namespace std;
int n,m,s,t;
typedef long long ll;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz; 
}

struct heap_node{
	ll dis;
	int id;
	heap_node(){
		
	}
	heap_node(int _id,ll _dis){
		id=_id;
		dis=_dis;
	}
	friend bool operator < (heap_node p,heap_node q){
		return p.dis>q.dis;
	}
};
priority_queue<heap_node>q;
ll dist[maxn+5];
ll cnt[maxn+5];
bool vis[maxn+5];
void dijkstra(int s,int t){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dist[s]=0;
	while(!q.empty()) q.pop();
	q.push(heap_node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(heap_node(y,dist[y]));
			}
		}
	} 
}

int d_in2[maxn+5];
void topo_sort(int s,int t){
	for(int i=2;i<=sz;i++){
		if(dist[E[i].to]==dist[E[i].from]+E[i].len){
			d_in2[E[i].to]++; 
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(d_in2[i]==0) q.push(i);
	}
	cnt[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]==dist[x]+E[i].len){
				cnt[y]+=cnt[x];
				cnt[y]%=mod;
				d_in2[y]--;
				if(d_in2[y]==0) q.push(y);
			}
		}
	}
}

int main(){
	int u,v,w;
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
	}
	dijkstra(s,t);
	topo_sort(s,t); 
	printf("dist=%lld cnt=%lld",dist[t],cnt[t]);
}
/*
6 7 1 6
1 2 1
1 3 1
3 4 1
3 5 2
2 5 1
4 6 1
5 6 1
*/ 

