#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
#define maxm 1000005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int len;
	int next;
	edge(){
		
	}
	edge(int u,int v,int w,int he){
		from=u;
		to=v;
		len=w;
		next=he;
	}
}E[maxm];
int sz=0;
int head[maxn];
void add_edge(int u,int v,int w){
	sz++;
	E[sz]=edge(u,v,w,head[u]);
	head[u]=sz;
}

struct node{
	int u;
	long long d;
	node(){
		
	}
	node(int x,long long dis){
		u=x;
		d=dis;
	}
	friend bool operator <(node a,node b){
		return a.d>b.d;
	} 
}; 
long long dist[maxn]; 
int used[maxn];
int last[maxn];
priority_queue<node>heap;
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	last[1]=0;
	node now,nex;
	heap.push(node(s,0));
	while(!heap.empty()){
		now=heap.top();
		heap.pop();
		int x=now.u;
		used[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!used[y]){
				if(dist[y]>dist[x]+E[i].len){
					dist[y]=dist[x]+E[i].len;
					last[y]=x;
					heap.push(node(y,dist[y]));
				}
			}
		}
	}
	
}
void print(int x){
	if(x==0) return;
	else{
		print(last[x]);
		printf("%d ",x);
	}
} 
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dijkstra(1);
	if(dist[n]==INF) printf("-1\n");
	else{
//		printf("%I64d\n",dist[n]); 
		print(n);
	}
} 
