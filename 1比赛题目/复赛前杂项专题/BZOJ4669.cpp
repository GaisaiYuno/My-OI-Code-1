//https://www.cnblogs.com/ZH-comld/p/10225915.html 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1000
#define maxm 5000
#define INF 0x3f3f3f3f3f3f3f3f 
using namespace std;
typedef long long ll;
int n,m;
ll k;
struct edge{
	int from;
	int to;
	int vol;
	int flow;
	int cost;
	int next;
}E[maxm*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w,int c){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].vol=w;
	E[sz].flow=w;
	E[sz].cost=c;
	E[sz].next=head[u];
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].vol=0;
	E[sz].flow=0;
	E[sz].cost=-c;
	E[sz].next=head[v];
	head[v]=sz;
} 
ll dist[maxn+5];
ll minf[maxn+5];
bool inq[maxn+5];
int pre[maxn+5];
bool spfa(int s,int t){
	queue<int>q;
	memset(dist,0x3f,sizeof(dist));
	memset(minf,0x3f,sizeof(minf));
	memset(pre,0,sizeof(pre));
	memset(inq,0,sizeof(inq));
	dist[s]=0;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&dist[y]>dist[x]+E[i].cost){
				dist[y]=dist[x]+E[i].cost;
				minf[y]=min(minf[x],(ll)E[i].flow);
				pre[y]=i;
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
bool check(ll mid){
	ll ans=0;
	int s=1,t=n;
	for(int i=2;i<=sz;i++) E[i].flow=E[i].vol;
	while(spfa(s,t)){
		update(s,t);
		ans+=max((mid-dist[t]+1)*minf[t],0ll);//从t=1到t=mid-dist[t]+1,共mid-dist[t]+1波人,每波minf[t]个 
	}
	return ans>=k;
}

void ini(){
	sz=1;
	memset(head,0,sizeof(head));
	memset(E,0,sizeof(E));
}
int main(){
	int u,v,w;
	while(scanf("%d %d %lld",&n,&m,&k)!=EOF){
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&u,&v,&w);
			u++;
			v++;
			add_edge(u,v,w,1);
		}
		ll l=0,r=1e12,ans=-1;//二分上界不能过大，否则会溢出 
		ll mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		if(ans==-1) printf("No solution\n");
		else printf("%lld\n",ans);
	}
	
} 
