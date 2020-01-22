#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<queue>
#define maxn 400000
#define maxm 500000
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w){
	printf("%d->%d cost=%d\n",u,v,w); 
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz; 
}

struct heap_node{
	ll dis;
	int id;
	heap_node(){
		
	}
	heap_node(int _id,ll _dis){
		id=_id;
		dis=_dis;
	}
	friend bool operator < (heap_node p,heap_node q){
		return p.dis>q.dis;
	}
};
ll dist[maxn+5];
ll cnt[maxn+5];
bool vis[maxn+5];
void dijkstra(int s,int t){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dist[s]=0;
	priority_queue<heap_node>q;
	q.push(heap_node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(heap_node(y,dist[y]));
			}
		}
	} 
}

int d_in2[maxn+5];
void topo_sort(int s,int t){
	for(int i=2;i<=sz;i++){
		if(dist[E[i].to]==dist[E[i].from]+E[i].len&&vis[E[i].from]&&vis[E[i].to]){
			d_in2[E[i].to]++; 
		}
	}
	queue<int>q;
	for(int i=0;i<=n;i++){
		if(d_in2[i]==0&&vis[i]) q.push(i);
	}
	cnt[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
//		printf("%d ",x);
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]==dist[x]+E[i].len&&vis[y]&&vis[x]){
				cnt[y]+=cnt[x];
				cnt[y]%=mod;
				d_in2[y]--;
				if(d_in2[y]==0) q.push(y);
			}
		}
	}
}


struct item{
	int in;
	int out;
	item(){
		
	}
	item(int _in,int _out){
		in=_in;
		out=_out;
	}
	friend bool operator < (item p,item q){
		if(p.out==q.out) return p.in<q.in;
		return p.out<q.out;
	} 
}a[maxn+5];
int tmp[maxn+5]; 
ll d_in[maxn+5];//Èë¶È 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].out,&a[i].in);
		tmp[i]=a[i].out;
	}
	sort(a+1,a+1+n);
	sort(tmp+1,tmp+1+n);
	int s=0,t=n+1;
	for(int i=1;i<=n;i++){
		int rb=upper_bound(tmp+1,tmp+1+n,a[i].in)-tmp-1;
		int pre=tmp[rb];
		int lb=lower_bound(tmp+1,tmp+1+n,pre)-tmp;
//		printf("%d->[%d,%d] cost=%d\n",i,lb,rb,a[i].in-a[lb].out); 
		if(lb<=rb){
			d_in[1]++;
			d_in[rb+1]--;
			for(int j=lb;j<=rb;j++){
				add_edge(i,j,a[i].in-a[lb].out); 
			}
		}else{
			add_edge(i,t,a[i].in);
		}
	}
	for(int i=1;i<=n;i++){
		d_in[i]+=d_in[i-1];
		if(d_in[i]==0) add_edge(s,i,0); 
	}
	dijkstra(s,t);
	topo_sort(s,t); 
	printf("%I64d\n",cnt[t]);
}

