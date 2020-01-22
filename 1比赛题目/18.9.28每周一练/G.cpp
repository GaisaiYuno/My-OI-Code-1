//转化成边跑最短路
//这样不能a->b->c就转化成边(a,b)不能到边(a,c)的问题
//然后最短路用边跑,dist[i]表示到边i终点距离
//最短路判断改一下就可以了 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#define maxn 3005
#define maxm 40005
#define maxk 100005
#define INF 0x3f3f3f3f
using namespace std;
int n,m,k;
struct ed {
	int u;
	int v;
	ed() {

	}
	ed(int a,int b) {
		u=a;
		v=b;
	}
	friend bool operator <(ed x,ed y) {
		if(x.u==y.u) return x.v<y.v;
		else return x.u<y.u;
	}
};
map<ed,int>hash_edge;//边的编号和两端点hash 
map<int,int>not_go[maxm];//not_go[i][j]=1表示不能从i到j 
struct edge {
	int from;
	int to;
	int next;
	int len;
	edge() {

	}
	edge(int u,int v,int w,int he) {
		from=u;
		to=v;
		next=he;
		len=w;
	}
};
int sz=1;
edge E[maxm];
int head[maxn];
void add_edge(int u,int v,int w) {
	sz++;
	E[sz]=edge(u,v,w,head[u]);
	hash_edge[ed(u,v)]=sz;
	head[u]=sz;
}
int p[maxm];
int dist[maxm];
int used[maxm];
struct node {
	int x;
	int d;
	node() {

	}
	node(int u,int dis) {
		x=u;
		d=dis;
	}
	friend bool operator <(node a,node b) {
		return a.d>b.d;
	}
};
priority_queue<node>heap;
void dijkstra(int s) {
	memset(dist,0x3f,sizeof(dist));
	for(int i=head[s]; i; i=E[i].next) {
		dist[i]=1;
		p[i]=-1;
		heap.push(node(i,1));
	}
	while(!heap.empty()) {
		node now=heap.top();
		heap.pop();
		int x=now.x;
		used[x]=1;
		for(int i=head[E[x].to]; i; i=E[i].next) {
			if(dist[i]>dist[x]+E[i].len&&!not_go[x].count(i)&&!used[i]) {
				//注意重边问题,这里可以从a->b再从b->a,见样例3 
				//所以不能写!used[i]&&!used[i^1] 
				dist[i]=dist[x]+E[i].len;
				p[i]=x;
				heap.push(node(i,dist[i]));
			}
		}
	}
}

void print(int x) {
	if(p[x]==-1) return;
	else print(p[x]);
	printf("%d ",E[x].from);
}
int main() {
	int u,v,a,b,c;
	int w;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	for(int i=1; i<=k; i++) {
		scanf("%d %d %d",&a,&b,&c);
		if(hash_edge.count(ed(a,b))) {
			int id1=hash_edge[ed(a,b)];
			int id2=hash_edge[ed(b,c)]; 
			not_go[id1][id2]=1;
		}
		swap(a,c);//不能a->b->c,也不能c->b->a 
		if(hash_edge.count(ed(a,b))) {
			int id1=hash_edge[ed(a,b)];
			int id2=hash_edge[ed(b,c)]; 
			not_go[id1][id2]=1;
		}
	}
	dijkstra(1);
	int ans=INF;
	int final=0;
	for(int i=head[n]; i; i=E[i].next) {
		if(dist[i^1]<ans) {
			ans=dist[i^1];
			final=i^1;
		}
	}
	if(ans<INF) {
		printf("%d\n",ans);
		printf("%d ",1);
		print(final);
		printf("%d",n);
	}else{
		printf("-1");
	} 
}

