//打倒SPFA邪教,Dijkstra万岁! 
//对于无向边构成的每个联通块，我们把它缩成一个点
//每次dijkstra的时候把一个块的节点全部入队
//然后类似拓扑排序，有向边连接联通块，只有某个联通块的入度=0时才能继续dijkstra
//这样dijkstra处理负权时就不会死循环 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<vector> 
#define maxn 100000
#define maxm 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,m,k,s;
struct edge {
	int from;
	int to;
	int next;
	ll len;
} E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,ll w) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

struct disjoint_set{
	int fa[maxn+5];
	void ini(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy) fa[fx]=fy;
	}
}S;
int bcnt;
int bel[maxn+5];
vector<int>block[maxn+5];
void ini_block(){
	bcnt=0;
	for(int i=1;i<=n;i++){
		int f=S.find(i);
		if(i==f){
			bcnt++;
			bel[i]=bcnt;
		}
	}	
	for(int i=1;i<=n;i++){
		int f=S.find(i);
		bel[i]=bel[f];
		block[bel[i]].push_back(i); 
	}
}

struct node {
	int id;
	ll dist;
	node() {

	}
	node(int _id,ll _dist) {
		id=_id;
		dist=_dist;
	}
	friend bool operator < (node p,node q) {
		if(p.dist==q.dist) return p.id<q.id;
		return p.dist<q.dist;
	}
};
bool vis[maxn+5];
ll dist[maxn+5];
int in[maxn+5];
void dijkstra_topo(int s) {
//	priority_queue<node>h;
	set<node>h;
	queue<int>q;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	for(int i=1;i<=bcnt;i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int id=q.front();//注意一般的队列里存的是联通块编号 
		q.pop();
		for(int i=0;i<(int)block[id].size();i++){//把一个联通块加入堆 
			int xx=block[id][i];
			h.insert(node(xx,dist[xx]));
		}
		while(!h.empty()){
			set<node>::iterator it=h.begin(); 
			int x=it->id;
			h.erase(*it);
			for(int i=head[x];i;i=E[i].next){
				int y=E[i].to;
				if(dist[y]>dist[x]+E[i].len){
					if(bel[x]==bel[y]){//更新联通块内最短路 
						h.erase(node(y,dist[y])); 
						dist[y]=dist[x]+E[i].len;
						h.insert(node(y,dist[y]));
					}
				}
				if(bel[x]!=bel[y]){//块外拓扑排序求最短路 
					dist[y]=min(dist[y],dist[x]+E[i].len);
					in[bel[y]]--;
					if(!in[bel[y]]) q.push(bel[y]);
				}
			}
		}
	}
}
int main(){
	int u,v,w;
	scanf("%d %d %d %d",&n,&m,&k,&s);
	S.ini(n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		S.merge(u,v);
	}
	ini_block();
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		in[bel[v]]++;
	}
	dijkstra_topo(s); 
	for(int i=1;i<=n;i++){
		if(dist[i]>=1e9) printf("NO PATH\n");
		else printf("%lld\n",dist[i]);
	} 
}
