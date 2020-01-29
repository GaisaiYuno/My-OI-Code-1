#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1005
#define maxm 1000005
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
	graph(){
		sz=0;
		memset(E,0,sizeof(E));
		memset(head,0,sizeof(head));
	}
	void add_edge(int u,int v,long long w) {
		sz++;
		E[sz]=edge(u,v,w,head[u]);
		head[u]=sz;
	}
	
	long long dist[maxn];
	int used[maxn];
	struct node{
		int x;
		long long d;
		node(){
			
		}
		node(int u,long long dis){
			x=u;
			d=dis;
		}
		friend bool operator <(node a,node b){
			return a.d>b.d;
		}
	};
	void dijkstra(int s){
		memset(dist,0x3f,sizeof(dist));
		memset(used,0,sizeof(used));
		dist[s]=0;
		priority_queue<node>heap;
		heap.push(node(s,0));
		node now;
		int x=0;
		while(!heap.empty()){
			now=heap.top();
			heap.pop();
			x=now.x;
			if(used[x]) continue;
			used[x]=1;
			for(int i=head[x];i;i=E[i].next){
				int y=E[i].to;
				if(dist[y]>dist[x]+E[i].len){
					dist[y]=dist[x]+E[i].len;
					heap.push(node(y,dist[y])); 
				}
			} 
		}
	}	
};
graph G1,G2;
int s,t;
struct driver{
	long long t;
	long long c;
}a[maxn];
int main() {
	scanf("%d %d",&n,&m);
	scanf("%d %d",&s,&t);
	int u,v;
	long long w;
	for(int i=1;i<=m;i++){
		scanf("%d %d %I64d",&u,&v,&w);
		G1.add_edge(u,v,w);
		G1.add_edge(v,u,w);
	}
	for(int i=1;i<=n;i++){
		scanf("%I64d %I64d",&a[i].t,&a[i].c);
	}
	for(int i=1;i<=n;i++){
		G1.dijkstra(i);
		for(int j=1;j<=n;j++){
			if(G1.dist[j]<=a[i].t&&i!=j){
//				printf("%d->%d dist=%I64d money=%I64d\n",i,j,G1.dist[j],a[i].c);
				G2.add_edge(i,j,a[i].c);
//				G2.add_edge(i,j,a[i].c);
			}
		}
	}
	G2.dijkstra(s);
	if(G2.dist[t]==INF){
		printf("-1\n");
	}else{
		printf("%I64d\n",G2.dist[t]); 
	}
}
