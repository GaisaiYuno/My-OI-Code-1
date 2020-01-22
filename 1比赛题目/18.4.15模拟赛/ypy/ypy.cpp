#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#define INF 4500000005 
#define maxn 4005
#define maxm 45005
using namespace std;
map<string,int>no;
int n,m;
int size;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm];
int head[maxn];
void ini(){
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	size=0;
}
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
}
long long dis[maxn];
int used[maxn];
struct heap_node{
	int u;
	long long dist;
	heap_node(int no,long long v){
		u=no;
		dist=v;
	}
	friend bool operator <(heap_node x,heap_node y){
		return x.dist>y.dist;
	}
}; 
void dijkstra(int s){
	priority_queue<heap_node>heap;
	memset(used,0,sizeof(used)); 
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[s]=0;
	heap.push(heap_node(s,0));
	while(!heap.empty()){
		heap_node now=heap.top();
		heap.pop();
		int u=now.u;
		if(used[u]) continue;
		used[u]=1;
		for(int i=head[u];i!=0;i=E[i].next){
			if(dis[E[i].to]>(long long)E[i].len+dis[u]) dis[E[i].to]=(long long)E[i].len+dis[u];
			heap.push(heap_node(E[i].to,dis[E[i].to]));
		} 
	} 
}
int main(){
//	freopen("ypy.in","r",stdin);
//	freopen("ypy.out","w",stdout);
	string tmp,t1,t2;
	int k1,k2,l;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>tmp;
		no[tmp]=i;
	}
	scanf("%d",&m);
	ini();
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		k1=no[t1];
		k2=no[t2];
		scanf("%d",&l);
		add_edge(k1,k2,l);
	}
	cin>>t1>>t2;
	int s=no[t1];
	int e=no[t2];
	dijkstra(s);
	if(dis[e]!=INF) printf("%lld\n",dis[e]);
	else printf("-1\n");
}
