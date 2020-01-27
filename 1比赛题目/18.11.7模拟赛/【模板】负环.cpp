#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
#define maxm 3005 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int t,n,m; 
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxm<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}
int inq[maxn];
int cnt[maxn];
long long dist[maxn];
void ini(){
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=0; 
}

struct queue{
	int Q[5000005];
	int head,tail;
	queue(){
		head=tail=0;
	}
	int front(){
		return Q[head];	
	}
	void pop(){
		head++;
	}
	void push(int x){
		Q[tail++]=x;
	}
	bool empty(){
		return head>tail;
	} 
	void clear(){
		head=tail=0;
	} 
}q;
int exist_neg_ring(){
	q.clear();
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		inq[i]=0;
		cnt[i]=0;
	}
	dist[1]=0;
	inq[1]=1;
	cnt[1]++;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(cnt[x]>n) return 1;
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				if(!inq[y]){
					q.push(y);
					cnt[y]++;
					inq[y]=1;
				}
			}
		}
	}
	return 0;
}

int main(){
	int u,v,w;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ini();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&u,&v,&w);
			add_edge(u,v,w);
			if(w>=0) add_edge(v,u,w);
		}
		if(exist_neg_ring()) printf("YE5\n");
		else printf("N0\n"); 
	}
} 
