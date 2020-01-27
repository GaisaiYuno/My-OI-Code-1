//https://www.luogu.org/problem/P4768
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define maxn 200000
#define maxm 400000
#define maxlogn 23
using namespace std;
typedef long long ll;
int t;
int n,m,q,k,s;
struct graph {
	struct edge {
		int from;
		int to;
		int next;
		int len;
		int height;
		friend bool operator < (edge p,edge q){
			return p.height>q.height;
		}
	}E[maxm*2+5]; 
	int sz=1;
	int head[maxn*2+5];
	void clear(){
		memset(head,0,sizeof(head));
		sz=1;
	}
	void add_edge(int u,int v,int l,int h){
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].next=head[u];
		E[sz].len=l;
		E[sz].height=h;
		head[u]=sz;
		sz++;
		E[sz].from=v;
		E[sz].to=u;
		E[sz].next=head[v];
		E[sz].len=l;
		E[sz].height=h;
		head[v]=sz;
	} 
}G;

struct tree{
	struct edge{
		int from;
		int to;
		int next;
	}E[(maxn+maxn)*2+5];
	int head[maxn+maxn+5];
	int sz=1;
	void clear(){
		memset(head,0,sizeof(head));
		sz=1;
	}
	void add_edge(int u,int v){
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].next=head[u];
		head[u]=sz;
		sz++;
		E[sz].from=v;
		E[sz].to=u;
		E[sz].next=head[v];
		head[v]=sz;
	}
}T; 


struct heap_node{
	ll dist;
	int id;
	heap_node(){
		
	}
	heap_node(int _id,ll _dist){
		id=_id;
		dist=_dist;
	}
	friend bool operator < (heap_node p,heap_node q){
		return p.dist>q.dist;
	}
};
int vis[maxn+5];
ll dist[maxn+5];
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	priority_queue<heap_node>q;
	q.push(heap_node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=G.head[x];i;i=G.E[i].next){
			int y=G.E[i].to;
			if(dist[y]>dist[x]+G.E[i].len){
				dist[y]=dist[x]+G.E[i].len;
				q.push(heap_node(y,dist[y]));
			}
		}
	}
}

int newn=0;
int fa[maxn*2+5]; 
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

int log2n;
int hi[maxn*2+5];
ll dmin[maxn*2+5];
int deep[maxn*2+5];
int anc[maxn*2+5][maxlogn+5]; 
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=T.head[x];i;i=T.E[i].next){
		int y=T.E[i].to;
		if(y!=fa){
			dfs(y,x);
			dmin[x]=min(dmin[x],dmin[y]);
		}
	}
}
ll query(int x,int lim){
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=0&&hi[anc[x][i]]>lim){
			x=anc[x][i];
		}
	}
	return dmin[x];
}
void kruskal(){//建出kruskal重构树 
	newn=n;
	for(int i=1;i<=n*2;i++) fa[i]=i;
	sort(G.E+2,G.E+1+G.sz);
	for(int i=2;i<=G.sz;i++){
		int x=G.E[i].from;
		int y=G.E[i].to;
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			newn++;
			T.add_edge(fx,newn);
			T.add_edge(fy,newn);
			fa[fx]=newn;
			fa[fy]=newn;
			hi[newn]=G.E[i].height;
		}
	}
	log2n=log2(newn);
	memset(dmin,0x3f,sizeof(dmin));
	for(int i=1;i<=n;i++) dmin[i]=dist[i]; 
	dfs(newn,0);
}

void ini(){
	T.clear();
	G.clear();
	memset(anc,0,sizeof(anc));
	memset(deep,0,sizeof(deep));
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(dmin,0x3f,sizeof(dmin));
}

int main() {
	freopen("return.in","r",stdin);
	freopen("return.out","w",stdout);
	int u,v,l,a;
	ll v0,p0;
	ll lastans;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		lastans=0;
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d %d %d",&u,&v,&l,&a);
			G.add_edge(u,v,l,a);
		}
		dijkstra(1);
		kruskal();
		scanf("%d %d %d",&q,&k,&s);
		for(int i=1;i<=q;i++){
			scanf("%lld",&v0);
			v0=(v0+k*lastans-1)%n+1;
			scanf("%lld",&p0);
			p0=(p0+k*lastans)%(s+1);
			lastans=query(v0,p0);
			printf("%lld\n",lastans);
		}	
	} 
}

