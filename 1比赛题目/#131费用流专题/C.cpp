//[CQOI2012][bzoj2668] 交换棋子
//https://www.cnblogs.com/dedicatus545/p/8781976.html 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 2000
#define maxm 100000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
namespace MCMF {
	struct edge {
		int from;
		int to;
		int next;
		int flow;
		int cost;
	} E[maxm*2+5];
	int head[maxn+5];
	int sz=1;
	void add_edge(int u,int v,int w,int c) {
//	printf("%d->%d flow=%d cost=%d\n",u,v,w,c);
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

	int dist[maxn+5];
	int minf[maxn+5];
	int pre[maxn+5];
	bool inq[maxn+5];
	bool spfa(int s,int t) {
		for(int i=s; i<=t; i++) {
			minf[i]=dist[i]=INF;
			inq[i]=0;
			pre[i]=0;
		}
		queue<int>q;
		dist[s]=0;
		q.push(s);
		inq[s]=1;
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			inq[x]=0;
			for(int i=head[x]; i; i=E[i].next) {
				int y=E[i].to;
				if(E[i].flow) {
					if(dist[y]>dist[x]+E[i].cost) {
						dist[y]=dist[x]+E[i].cost;
						pre[y]=i;
						minf[y]=min(minf[x],E[i].flow);
						if(!inq[y]) {
							q.push(y);
							inq[y]=1;
						}
					}
				}
			}
		}
		return dist[t]!=INF;
	}
	bool vis[maxn+5];
	int dfs(int x,int t,int minf,int &cost) {
		if(x==t) {
			cost+=minf*dist[t];
			return minf;
		}
		int rest=minf,k;
		vis[x]=1;
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(!vis[y]&&E[i].flow&&dist[y]==dist[x]+E[i].cost) {
				k=dfs(y,t,min(rest,E[i].flow),cost);
				E[i].flow-=k;
				E[i^1].flow+=k;
				rest-=k;
				if(k==0) dist[y]=INF;
				if(rest==0) break;
			}
		}
		vis[x]=0;
		return minf-rest;
	}
	pair<int,int> mcmf(int s,int t) {
		int cost=0,flow=0,now;
		while(spfa(s,t)) {
			while((now=dfs(s,t,INF,cost))) flow+=now;
		}
		return make_pair(flow,cost);
	}
}
int pre[maxn+5][maxn+5];
int nex[maxn+5][maxn+5];
int lim[maxn+5][maxn+5];
inline int get_in(int x,int y) {
	return (x-1)*m+y;
}
inline int get_now(int x,int y) {
	return (x-1)*m+y+n*m;
}
inline int get_out(int x,int y) {
	return (x-1)*m+y+n*m*2;
}
int cnt_black=0;
const int dirx[9]= {-1,-1,-1,0,0,1,1,1},diry[9]= {-1,0,1,-1,1,-1,0,1};
int main() {
	scanf("%d %d",&n,&m);
	int s=0,t=n*m*3+1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%1d",&pre[i][j]);
			if(pre[i][j]==1) {
				MCMF::add_edge(s,get_now(i,j),1,0);
				cnt_black++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%1d",&nex[i][j]);
			if(nex[i][j]==1) MCMF::add_edge(get_now(i,j),t,1,0);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%1d",&lim[i][j]);
			if(pre[i][j]==1&&nex[i][j]==0) {
				MCMF::add_edge(get_in(i,j),get_now(i,j),lim[i][j]/2,0);
				MCMF::add_edge(get_now(i,j),get_out(i,j),(lim[i][j]+1)/2,0);//因为有黑棋进到now,流量要大
			} else if(pre[i][j]==0&&nex[i][j]==1) {
				MCMF::add_edge(get_in(i,j),get_now(i,j),(lim[i][j]+1)/2,0);//因为有黑棋从now出去,流量要大，恰好保证了流量平衡
				MCMF::add_edge(get_now(i,j),get_out(i,j),lim[i][j]/2,0);
			} else {
				MCMF::add_edge(get_in(i,j),get_now(i,j),lim[i][j]/2,0);
				MCMF::add_edge(get_now(i,j),get_out(i,j),lim[i][j]/2,0);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=0; k<8; k++) {
				int xx=i+dirx[k],yy=j+diry[k];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m) {
					MCMF::add_edge(get_out(i,j),get_in(xx,yy),INF,1);
				}
			}
		}
	}
	pair<int,int>tmp=MCMF::mcmf(s,t);
	int flow=tmp.first,cost=tmp.second;
	if(flow!=cnt_black) printf("-1\n");//用流量来判断是否有解
	else printf("%d\n",cost);
}
/*
2 2
00
01
10
00
22
22
*/

