//For Selina
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib> 
#include<queue>
#define INF 0x3f3f3f3f3f3f3f3f 
#define maxn 10000
#define maxm 3000000 
using namespace std;
typedef long long ll;
int n,m;
inline void qread(int& x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qread(ll& x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

struct node{
	ll x;
	ll y;
	int c;
}a[maxn+5],b[maxn+5];
	
inline ll get_dist(node p,node q){
	return abs(p.x-q.x)+abs(p.y-q.y);
}





namespace network_flow{
	struct edge{
		int from;
		int to;
		int next;
		ll flow;
		ll cost;
	}E[maxm+5];
	int head[maxn+5]; 
	int sz=1;
	void add_edge(int u,int v,ll w,ll c){
#ifdef DEBUG
//		printf("%d->%d vol=%lld cost=%lld\n",u,v,w,c);	
#endif
		c=-c;
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].flow=w;
		E[sz].cost=c;
		E[sz].next=head[u];
		head[u]=sz;
		sz++;
		E[sz].from=v;
		E[sz].to=u;
		E[sz].flow=0;
		E[sz].cost=-c;
		E[sz].next=head[v];
		head[v]=sz;
	}
	
	bool inq[maxn+5];
	int pre[maxn+5]; 
	ll minf[maxn+5];
	ll dist[maxn+5]; 
	bool spfa(int s,int t){
		for(int i=s;i<=t;i++){
			inq[i]=0;
			pre[i]=0;
			dist[i]=INF;
			minf[i]=INF;
		} 
		queue<int>q;
		q.push(s);
		inq[s]=1;
		dist[s]=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			inq[x]=0;
			for(int i=head[x];i;i=E[i].next){
				int y=E[i].to;
				if(E[i].flow&&dist[y]>dist[x]+E[i].cost){
					dist[y]=dist[x]+E[i].cost;
					pre[y]=i;
					minf[y]=min(minf[x],E[i].flow);
					if(!inq[y]){
						q.push(y);
						inq[y]=1;
					}
				}
			}
		}
		return dist[t]!=INF;
	}
	void update(int s,int t){
		int x=t;
		while(x!=s){
			int i=pre[x];
			E[i].flow-=minf[t];
			E[i^1].flow+=minf[t];
			x=E[i].from;
		}
	}
	void print_edge(){
		for(int i=2;i<=sz;i+=2){
			printf("%d->%d vol=%lld cost=%lld\n",E[i].from,E[i].to,E[i].flow,E[i].cost);	
		} 
		printf("\n"); 
	}
	ll mcmf(int s,int t){
		
		ll flow=0,cost=0;
		while(spfa(s,t)){
			flow+=minf[t];
			cost+=minf[t]*dist[t];
			update(s,t);
//			printf("%lld\n",cost); 
//			print_edge(); 
		} 
		return -cost;
	}
	void solve(){
		int s=0,t=n*2+1;
		for(int i=1;i<=n;i++){
			add_edge(s,i,a[i].c,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				add_edge(i,j+n,INF,get_dist(a[i],b[j]));
			}
		}
		for(int i=1;i<=n;i++){
			add_edge(i+n,t,b[i].c,0);
		}
		printf("%lld\n",mcmf(s,t)); 
	}
}



int main(){
//	freopen("1.in","r",stdin);
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i].x);
		qread(a[i].y);
		qread(a[i].c);
	} 
	for(int i=1;i<=n;i++){
		qread(b[i].x);
		qread(b[i].y);
		qread(b[i].c);
	} 
	network_flow::solve();
}
/*
2
1 1 1
2 2 1
3 3 1
4 4 1
*/
