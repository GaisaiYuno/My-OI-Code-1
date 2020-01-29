#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<queue>
#define maxn 1000000
#define maxm 3000000
#define mod 1000000007
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,new_n;
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

struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int in[maxn+5];
int sz=1;
void add_edge(int u,int v,int w){
//	printf("%d->%d cost=%d\n",u,v,w); 
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz; 
	in[v]++;
}


ll dist[maxn+5];
ll cnt[maxn+5];


int seq[maxn+5];
void topo_sort(int s,int t){
	int len=0;
	queue<int>q;
	for(int i=s;i<=t;i++){
		if(!in[i]) q.push(i);
	}
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		seq[++len]=x;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			in[y]--;
			if(!in[y]) q.push(y); 
		}
	}
	for(int i=1;i<=len;i++){
		int x=seq[i];
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len) dist[y]=dist[x]+E[i].len;
		}
	}
	memset(cnt,0,sizeof(cnt));
	cnt[s]=1;
	for(int i=1;i<=len;i++){
		int x=seq[i];
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]==dist[x]+E[i].len){
				cnt[y]+=cnt[x];
				cnt[y]%=mod;
			}
		}
	}
	
}

struct segment_tree{
	struct tree_node{
		int l;
		int r;
	}tree[maxn*4+5];
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			new_n=max(new_n,pos+n);
			add_edge(pos+n,l,-a[l].out);
			return;
		}
		int mid=(l+r)>>1;
		add_edge(pos+n,(pos<<1)+n,0);
		add_edge(pos+n,(pos<<1|1)+n,0);
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int L,int R,int ux,int uv,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			add_edge(ux,pos+n,uv);
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,ux,uv,pos<<1);
		if(R>mid) update(L,R,ux,uv,pos<<1|1);
	} 
}T;



ll cov[maxn+5];//统计每个节点可以被套的次数，如果cov[i]=0,则由s向i连边
int main(){
	scanf("%d",&n);
	new_n=0;
	new_n+=n;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].out,&a[i].in);
		tmp[i]=a[i].out;
	}
	sort(a+1,a+1+n);
	sort(tmp+1,tmp+1+n);
	T.build(1,n,1);
	int s=0,t=new_n+1;
	for(int i=1;i<=n;i++){
		int rb=upper_bound(tmp+1,tmp+1+n,a[i].in)-tmp-1;
		if(rb>=1){
			cov[1]++;//差分统计，相当于[1,rb]+1
			cov[rb+1]--;
			T.update(1,rb,i,a[i].in,1);
		}else{
			add_edge(i,t,a[i].in);
		}
	}
	for(int i=1;i<=n;i++){
		cov[i]+=cov[i-1];
		if(cov[i]==0) add_edge(s,i,0); 
	}
	topo_sort(s,t); 
	printf("%I64d\n",cnt[t]);
}
