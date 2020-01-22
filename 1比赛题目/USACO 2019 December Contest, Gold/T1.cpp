#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define INF 0x3f3f3f3f
#define maxn 1000
#define maxm 1000
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int cost;
	int flow;	
}E[maxm*2+5];
int esz=1;
int head[maxn+5];
void add_edge(int u,int v,int w,int c){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].flow=w;
	E[esz].cost=c;
	E[esz].next=head[u];
	head[u]=esz;
}

struct node{
	int id;
	int dist;
	node(){
		
	}
	node(int _id,int _dist){
		id=_id;
		dist=_dist;
	}
	friend bool operator < (node p,node q){
		return p.dist>q.dist;
	}
};
int dist[maxn+5];
bool vis[maxn+5];
bool ban[maxm*2+5];
int dijkstra(int s,int t,int lim){
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		vis[i]=0;
	}
	priority_queue<node>q;
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(ban[i]||E[i].flow<lim) continue;
			if(dist[y]>dist[x]+E[i].cost){
				dist[y]=dist[x]+E[i].cost;
				q.push(node(y,dist[y]));
			}
		}
	}
	return dist[t];
}

int main(){
//#ifndef LOCAL
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
//#endif
	int u,v,w,c;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&u,&v,&c,&w);
		add_edge(u,v,w,c);
		add_edge(v,u,w,c);
	}
	double ans=0;
	int s=1,t=n;
	for(int i=2;i<=esz;i++){
		int u=E[i].from,v=E[i].to; 
		ban[i]=ban[i^1]=1;
		int c1=dijkstra(u,s,E[i].flow);
		int c2=dijkstra(v,t,E[i].flow);
		int cost=c1+c2+E[i].cost;
		ans=max(ans,1.0*E[i].flow/cost);	
		ban[i]=ban[i^1]=0;
	}
	printf("%lld\n",(long long)floor(ans*1000000));
}
