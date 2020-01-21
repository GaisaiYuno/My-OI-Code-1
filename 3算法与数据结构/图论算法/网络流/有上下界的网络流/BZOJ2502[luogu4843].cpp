#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
#define maxm 500005
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
namespace max_flow {
	struct edge {
		int from;
		int to;
		int next;
		int rest;
	} E[maxm<<1];
	int sz=1;
	int head[maxn];
	void add_edge(int u,int v,int w) {
//		printf("%d %d %d\n",u,v,w);
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].rest=w;
		E[sz].next=head[u];
		head[u]=sz;
		sz++;
		E[sz].from=v;
		E[sz].to=u;
		E[sz].rest=0;
		E[sz].next=head[v];
		head[v]=sz;
	}

	int deep[maxn];
	bool bfs(int s,int t) {
		queue<int>q;
		memset(deep,0,sizeof(deep));
		deep[s]=1;
		q.push(s);
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			for(int i=head[x]; i; i=E[i].next) {
				int y=E[i].to;
				if(E[i].rest) {
					if(!deep[y]) {
						deep[y]=deep[x]+1;
						q.push(y);
					}
				}
			}
		}
		return deep[t]!=0;
	}
	int dfs(int x,int t,int minf) {
		if(x==t) return minf;
		int rest=minf,k;
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(E[i].rest&&deep[y]==deep[x]+1) {
				k=dfs(y,t,min(rest,E[i].rest));
				rest-=k;
				E[i].rest-=k;
				E[i^1].rest+=k;
				if(k==0) deep[y]=0;
				if(rest==0) break;
			}
		}
		return minf-rest;
	}
	int dinic(int s,int t) {
		int ans=0,now;
		while(bfs(s,t)) {
			while(now=dfs(s,t,INF)) ans+=now;
		}
		return ans;
	}
}

namespace bound_flow{
	struct edge{
		int from;
		int to;
		int lb;
		int rb;
		int hash_id;
	}E[maxm<<1];
	int ecnt=1;
	void add_edge(int u,int v,int l,int r){
//		printf("%d %d %d %d\n",u,v,l,r);
		ecnt++;
		E[ecnt].from=u;
		E[ecnt].to=v;
		E[ecnt].lb=l;
		E[ecnt].rb=r;
	} 
	int dflow[maxn];
	int solve(int s,int t,int n){
		int sum=0;
		int ss=0,tt=n+1;
		add_edge(t,s,0,INF);
		for(int i=1;i<=ecnt;i++){
			max_flow::add_edge(E[i].from,E[i].to,E[i].rb-E[i].lb);
			E[i].hash_id=max_flow::sz;
			dflow[E[i].from]-=E[i].lb;
			dflow[E[i].to]+=E[i].lb;
		}
		for(int i=1;i<=n;i++){
			if(dflow[i]<0){
				max_flow::add_edge(i,tt,-dflow[i]);
			}
			if(dflow[i]>0){
				max_flow::add_edge(ss,i,dflow[i]);
				sum+=dflow[i];
			}
		}
		int ans=0;
		if(max_flow::dinic(ss,tt)==sum){
			int k=E[ecnt].hash_id;
			ans+=max_flow::E[k].rest;
			max_flow::E[k].rest=max_flow::E[k^1].rest=0;
			ans-=max_flow::dinic(t,s);
			return ans;
		}else return 0;
		
	}
}

int ind[maxn],outd[maxn];
int a[105][105];
int main() {
	int x,y;
	int cnt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++){
			cnt++;
			scanf("%d",&a[i][j]);
			ind[y]++;
			outd[i]++;
		} 
	}
	m=cnt;
	cnt=0;
	int s=n+m*2+1,t=n+m*2+2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i][0];j++){
			cnt++;
			bound_flow::add_edge(i,n+cnt,0,INF);
			bound_flow::add_edge(n+cnt,n+m+cnt,1,INF);
			bound_flow::add_edge(n+m+cnt,a[i][j],0,INF);
		}
	}
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			bound_flow::add_edge(s,i,0,INF);
		}
		if(outd[i]==0){
			bound_flow::add_edge(i,t,0,INF);
		}
	}
	printf("%d\n",bound_flow::solve(s,t,n+m*2+2));
}
/*
5
2 2 5
1 4
1 2
0
0
*/
