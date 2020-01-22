#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 40000
#define maxm 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,m;
struct edge {
	int from;
	int to;
	int next;
	ll len;
} E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,ll w) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

struct node {
	int id;
	ll dist;
	node() {

	}
	node(int _id,ll _dist) {
		id=_id;
		dist=_dist;
	}
	friend bool operator < (node p,node q) {
		return p.dist>q.dist;
	}
};
bool vis[maxn+5];
ll dist[maxn+5];
int mark[maxm*2+5];
ll dijkstra() {
	priority_queue<node>q;
	for(int i=1; i<=n; i++) {
		vis[i]=0;
		dist[i]=INF;
	}
	dist[1]=0;
	q.push(node(1,0));
	while(!q.empty()) {
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(mark[i]==-1) continue;
			if(dist[y]>dist[x]+E[i].len) {
				dist[y]=dist[x]+E[i].len;
				q.push(node(y,dist[y]));
			}
		}
	}
	ll ans=INF;
	//扫描入边统计答案
	for(int i=head[1]; i; i=E[i].next) {
		if(mark[i^1]==1) {
			ans=min(ans,dist[E[i^1].from]+E[i^1].len);
		}
	}
	return ans;
}

int main() {
	int u,v,w1,w2;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d %d",&u,&v,&w1,&w2);
		add_edge(u,v,w1);
		add_edge(v,u,w2);
	}
	ll ans=INF;
//	dijkstra(1);
	for(int b=0; b<=20; b++) {
		for(int i=1; i<=m; i++) mark[i]=0;
		//满足条件的路径出边和入边一定有1位二进制不同
		//枚举每一位，把那一位为0的强制指定为出边,1的指定为入边
		for(int i=head[1]; i; i=E[i].next) {
			if(i&(1<<b)) {
				mark[i]=1;//标记哪条边可以走,1为可以走
				mark[i^1]=-1;
			} else {
				mark[i]=-1;
				mark[i^1]=1;
			}
		}
		ans=min(ans,dijkstra());
		for(int i=head[1]; i; i=E[i].next) {
			if(i&(1<<b)) {
				mark[i]=-1;//交换出入边再跑一次 
				mark[i^1]=1;
			} else {
				mark[i]=1;
				mark[i^1]=-1;
			}
		}
		ans=min(ans,dijkstra());
	}
	printf("%lld\n",ans);
}
