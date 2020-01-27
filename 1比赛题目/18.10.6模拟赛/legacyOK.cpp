//建一棵线段树 
//首先将线段树的各条边加入图 
//从u到[l,r]中的点连边，相当于u向[l,r]所属的线段树节点编号连边
//最后图有nlogn个点
//再跑dijkstra就可以了 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 900005
#define maxm 3600005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,s;
struct edge{
	int from;
	int to;
	int next;
	long long len;
}E[maxm];
int head[maxn];
int sz;
void add_edge(int u,int v,long long w){
//	printf("%d->%d\n",u,v);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz; 
} 

struct node{
	int l;
	int r;
	int id[2];//id[0]表示有边v->[l,r]时该点的编号，id[1]反之 
}tree[maxn<<2];
int cnt;
void push_up(int pos,int type){
	if(type==0){
		add_edge(tree[pos].id[type],tree[pos<<1].id[type],0);
		add_edge(tree[pos].id[type],tree[pos<<1|1].id[type],0);
	}else{
		add_edge(tree[pos<<1].id[type],tree[pos].id[type],0);
		add_edge(tree[pos<<1|1].id[type],tree[pos].id[type],0);
	}
} 
void build(int l,int r,int type,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].id[type]=++cnt;
	if(l==r){
		if(type==0){
			add_edge(tree[pos].id[type],l,0);
			//将点i和区间[i,i]连起来，边权0，相当于在线段树节点和图之间做连接 
		}else{
			add_edge(l,tree[pos].id[type],0);
		} 
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,type,pos<<1); 
	build(mid+1,r,type,pos<<1|1);
	push_up(pos,type); 
}

void update(int L,int R,int type,int to,long long w,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		if(type==0){
			add_edge(to,tree[pos].id[type],w);
		}else{
			add_edge(tree[pos].id[type],to,w);
		} 
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,type,to,w,pos<<1);
	if(R>mid) update(L,R,type,to,w,pos<<1|1);
} 

int used[maxn];
long long dist[maxn];
struct heap_node{
	int u;
	long long d;
	heap_node(){
		
	}
	heap_node(int x,long long dis){
		u=x;
		d=dis;
	}
	friend bool operator <(heap_node a,heap_node b){
		return a.d>b.d;
	} 
}; 
priority_queue<heap_node>heap;
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	heap_node now,nex;
	heap.push(heap_node(s,0));
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
					heap.push(heap_node(y,dist[y]));
				}
			}
		}
	}
	
}

int main(){
	scanf("%d %d %d",&n,&m,&s);
	int type;
	long long w;
	int l,r,u,v;
	cnt=n;
	build(1,n,0,1);
	build(1,n,1,1);
	for(int i=1;i<=m;i++){
		scanf("%d",&type);
		if(type==1){
			scanf("%d %d %lld",&u,&v,&w);
			add_edge(u,v,w);
		}else{
			type=type-2;//2->0,3->1
			scanf("%d %d %d %lld",&v,&l,&r,&w);
			update(l,r,type,v,w,1);
		}
	}
	dijkstra(s);
	for(int i=1;i<=n;i++){
		if(dist[i]>=INF) printf("-1");
		else printf("%lld",dist[i]);
		if(i!=n) putchar(' ');
	}
}
