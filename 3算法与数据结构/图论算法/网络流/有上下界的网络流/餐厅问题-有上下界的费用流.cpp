//https://www.cnblogs.com/five20/p/8417493.html
//此题会爆int
//洛谷输入格式和loj不一样 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10005
#define maxm 500005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
typedef long long ll;
namespace EK {
	struct edge {
		int from;
		int to;
		int next;
		ll flow;
		ll cost;
	} E[maxm<<1];
	int head[maxn];
	int sz=1;
	void add_edge(int u,int v,ll w,int c) {
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].next=head[u];
		E[sz].flow=w;
		E[sz].cost=c;
		head[u]=sz;
		sz++;
		E[sz].from=v;
		E[sz].to=u;
		E[sz].next=head[v];
		E[sz].flow=0;
		E[sz].cost=-c;
		head[v]=sz;
	}
	ll dist[maxn];
	ll minf[maxn];
	int pre[maxn];
	int inq[maxn];
	bool spfa(int s,int t) {
		memset(dist,0x3f,sizeof(dist));
		memset(inq,0,sizeof(inq));
		queue<int>q;
		q.push(s);
		inq[s]=1;
		dist[s]=0;
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			inq[x]=0;
			for(int i=head[x]; i; i=E[i].next) {
				int y=E[i].to;
				if(E[i].flow) {
					if(dist[y]>dist[x]+E[i].cost) {
						dist[y]=dist[x]+E[i].cost;
						minf[y]=min(minf[x],E[i].flow);
						pre[y]=i;
						if(!inq[y]) {
							inq[y]=1;
							q.push(y);
						}
					}
				}
			}
		}
		if(dist[t]==INF) return 0;
		else return 1;
	}
	void update(int s,int t) {
		int x=t;
		while(x!=s) {
			int i=pre[x];
			E[i].flow-=minf[t];
			E[i^1].flow+=minf[t];
			x=E[i^1].to;
		}
	}
	pair<ll,ll> mcmf(int s,int t) {
		memset(minf,0x3f,sizeof(minf));
		ll mincost=0,maxflow=0;
		while(spfa(s,t)) {
			update(s,t);
			mincost+=dist[t]*minf[t];
			maxflow+=minf[t];
		}
		return make_pair(mincost,maxflow);
	}
}

namespace bound_mcmf {
	using namespace EK;
	int cntv,cnte;
	int from[maxm],to[maxm];
	ll lower[maxm],upper[maxm];
	ll cost[maxm];
	ll dflow[maxn];//入流-出流
	int hash_id[maxm];
	void adde(int u,int v,ll l,ll r,ll c) {
//		printf("%d->%d [%d,%d] cost=%d\n",u,v,l,r,c);
		cnte++;
		from[cnte]=u;
		to[cnte]=v;
		lower[cnte]=l;
		upper[cnte]=r;
		cost[cnte]=c;
	}
	ll solve(int s,int t) {
		ll ans=0;
		int ss=cntv+1,tt=cntv+2;
		adde(t,s,0,INF,0);
		for(int i=1; i<=cnte; i++) {
			add_edge(from[i],to[i],upper[i]-lower[i],cost[i]);
			hash_id[i]=sz;
			dflow[from[i]]-=lower[i];
			dflow[to[i]]+=lower[i];
			ans+=cost[i]*lower[i];
		}
		ll sum=0;
		for(int i=1; i<=cntv; i++) {
			if(dflow[i]<0) {
				add_edge(i,tt,-dflow[i],0);
			} else if(dflow[i]>0) {
				add_edge(ss,i,dflow[i],0);
				sum+=dflow[i];
			}
		}
		pair<ll,ll> p=mcmf(ss,tt);
		if(p.second==sum) { 
//			printf("flow1=%d\n",p.first);
			ans+=p.first;
			E[hash_id[cnte]].flow=E[hash_id[cnte]^1].flow=0;
			return ans;
		} else return 0;
	}
}

int p,fcost,fday,scost,sday;
int r[maxn];

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&r[i]);
	scanf("%d %d %d %d %d",&p,&fday,&fcost,&sday,&scost);
	int s=0,t=n*2+1;
	bound_mcmf::cntv=n*2+1;
	//i今天清洗的,i+n今天使用的 
	for(int i=1; i<=n; i++) {
		bound_mcmf::adde(s,i,0,INF,p);//买新毛巾 
	}
	for(int i=1; i<n; i++) {
		bound_mcmf::adde(i,i+1,0,INF,0);//脏毛巾可以留到下一天再洗 
	}
	for(int i=1; i<=n; i++) {
		bound_mcmf::adde(i,i+n,r[i],r[i],0);
		//当天洗的和用的恰好相等 
	} 
	for(int i=1;i<=n;i++){
		bound_mcmf::adde(i+n,t,0,r[i],0);
	}
	for(int i=1; i+fday<=n; i++) {
		bound_mcmf::adde(i+n,i+fday,0,INF,fcost);
	}
	for(int i=1; i+sday<=n; i++) {
		bound_mcmf::adde(i+n,i+sday,0,INF,scost);
	}
	printf("%lld\n",bound_mcmf::solve(s,t));
}

