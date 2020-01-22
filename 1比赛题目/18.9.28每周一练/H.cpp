#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<vector>
#define maxn 100005
#define maxm 200005
#define maxlog 32
#define maxk 45
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
struct graph {
	struct edge {
		int from;
		int to;
		int next;
		long long len;
		edge() {

		}
		edge(int u,int v,long long w,int he) {
			from=u;
			to=v;
			next=he;
			len=w;
		}
	};
	int sz;
	edge E[maxm];
	int head[maxn];
	void add_edge(int u,int v,long long w) {
		sz++;
		E[sz]=edge(u,v,w,head[u]);
		head[u]=sz;
	}
	graph() {
		sz=0;
		memset(head,0,sizeof(head));
	}
};
graph T,G;

int deep[maxn];
long long dist_tree[maxn];
int anc[maxn][maxlog];
int log2n;
void dfs(int x,int fa) {
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1; i<=log2n; i++) {
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=T.head[x]; i; i=T.E[i].next) {
		int y=T.E[i].to;
		if(y!=fa) {
			dist_tree[y]=dist_tree[x]+T.E[i].len;
			dfs(y,x);
		}
	}
}

int lca(int x,int y) {
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n; i>=0; i--) {
		if(deep[anc[x][i]]>=deep[y]) {
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=log2n; i>=0; i--) {
		if(anc[x][i]!=anc[y][i]) {
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

long long get_dis_tree(int x,int y) {
	return dist_tree[x]+dist_tree[y]-2*dist_tree[lca(x,y)];
}

int sp[maxn];
int k;
long long dist_graph[maxn][maxk];
int used[maxn];
struct node {
	int x;
	long long d;
	node() {

	}
	node(int u,long long dis) {
		x=u;
		d=dis;
	}
	friend bool operator <(node a,node b) {
		return a.d>b.d;
	}
};
priority_queue<node>heap;
void dijkstra(int id) {
	int s=sp[id];
	for(int i=1; i<=n; i++) dist_graph[i][id]=INF;
	memset(used,0,sizeof(used));
	dist_graph[s][id]=0;
	while(!heap.empty()) heap.pop();
	heap.push(node(s,dist_graph[s][id]));
	node now;
	int x=0;
	while(!heap.empty()) {
		now=heap.top();
		heap.pop();
		x=now.x;
		used[x]=1;
		for(int i=G.head[x]; i; i=G.E[i].next) {
			int y=G.E[i].to;
			if(!used[y]&&dist_graph[y][id]>dist_graph[x][id]+G.E[i].len) {
				dist_graph[y][id]=dist_graph[x][id]+G.E[i].len;
				heap.push(node(y,dist_graph[y][id]));
			}
		}
	}
}

int q;
struct disjoint_set {
	int fa[maxn];
	void ini() {
		for(int i=1; i<=n; i++) fa[i]=i;
	}
	int find(int x) {
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
};
disjoint_set S;
int main() {
	int u,v,fu,fv;
	long long w;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1;
	S.ini();
//	if(n==100)printf("debug: %d",k);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %I64d",&u,&v,&w);
		fu=S.find(u);
		fv=S.find(v);
		if(fu!=fv) {
			S.fa[fu]=fv;
			T.add_edge(u,v,w);
			T.add_edge(v,u,w);
			G.add_edge(u,v,w);
			G.add_edge(v,u,w);
		} else {
			G.add_edge(u,v,w);
			G.add_edge(v,u,w);
//			printf("debug: %d %d\n",u,v);
			sp[++k]=u;
			sp[++k]=v;
		}
	}
//	printf("debug: %d\n",k);
	sort(sp+1,sp+1+k);
	k=unique(sp+1,sp+1+k)-sp-1;
//	printf("debug: %d\n",k);
	deep[1]=1;
	dfs(1,0);
	for(int i=1; i<=k; i++) {
		dijkstra(i);
	}
	scanf("%d",&q);
	long long ans=0;
	for(int i=1; i<=q; i++) {
		scanf("%d %d",&u,&v);
		ans=get_dis_tree(u,v);
		for(int j=1; j<=k; j++) {
			ans=min(ans,dist_graph[u][j]+dist_graph[v][j]);
		}
		printf("%I64d\n",ans);
	}
}
