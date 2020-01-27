#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#define maxn 100005
#define maxm 100005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
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
set<int>ari[maxn];//记录每个点人到达的时间
int get_time(int x,int t) { //求一个人t时刻到达x点,何时能离开
	while(ari[x].find(t)!=ari[x].end()) t++;
	return t;
}
long long dist[maxn];
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
void dijkstra(int s) {
	memset(dist,0x3f,sizeof(dist));
	memset(used,0,sizeof(used));
	dist[s]=0;
	dist[s]=get_time(s,dist[s]);
	priority_queue<node>heap;
	heap.push(node(s,dist[s]));
	node now;
	int x=0;
	while(!heap.empty()) {
		now=heap.top();
		heap.pop();
		x=now.x;
		used[x]=1;
		long long newd=get_time(x,dist[x]);
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(!used[y]&&dist[y]>newd+E[i].len) {
				dist[y]=newd+E[i].len;
				heap.push(node(y,dist[y]));
			}
		}
	}
}

void SPFA(int s) {
	memset(dist,0x3f,sizeof(dist));
	memset(used,0,sizeof(used));
	dist[s]=0;
	dist[s]=get_time(s,dist[s]);
	queue<int>q;
	while(!q.empty()) q.pop();
	q.push(s);
	used[s]=1;
	int x=0;
	while(!q.empty()) {
		x=q.front();
		q.pop();
		used[x]=0;
		long long newd=get_time(x,dist[x]);
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(dist[y]>newd+E[i].len) {
				dist[y]=newd+E[i].len;
				if(!used[y]) {
					q.push(y);
					used[y]=1;
				}

			}
		}
	}
}
int main() {
	int u,v,w,cnt,x;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&cnt);
		for(int j=1; j<=cnt; j++) {
			scanf("%d",&x);
			ari[i].insert(x);
		}
	}
	SPFA(1);
	if(dist[n]==INF) printf("-1");
	else printf("%d",dist[n]);
}
