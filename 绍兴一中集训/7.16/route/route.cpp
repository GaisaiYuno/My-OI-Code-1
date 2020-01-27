#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 500000
#define maxm 4000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
long long A,B,C;
struct route{
	int x;
	int y;
	long long p;
	long long q;
}a[maxn+5];
inline long long func(long long x){
	return A*x*x+B*x+C;
}

struct edge{
	int from;
	int to;
	int next;
	long long len;
}E[maxm*maxm+5];
int head[maxn+5];
int sz=0;
void add_edge(int u,int v,long long w){
//	printf("%d->%d len=%lld\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

long long dist[maxn+5];
long long vis[maxn+5];
struct node{
	int id;
	long long dis;
	node(){
		
	}
	node(int _id,long long _dis){
		id=_id;
		dis=_dis;
	}
	friend bool operator < (node p,node q){
		return p.dis>q.dis;
	}
};
void dijkstra(int s){
	priority_queue<node>q;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(node(y,dist[y]));
			}
		}
	}
}

namespace brute_force{
	void solve(){
		int s=0;
		for(int i=1;i<=m;i++){
			if(a[i].x==1) add_edge(s,i,func(a[i].p));
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j&&a[i].p>=a[j].q&&a[i].x==a[j].y){
					add_edge(j,i,func(a[i].p-a[j].q));
				}
			}
		}
		dijkstra(s);
		long long ans=INF;
		for(int i=1;i<=m;i++){
			if(a[i].y==n){
				ans=min(ans,dist[i]+a[i].q);
			}
		}
		printf("%lld\n",ans);
	}
	
}

namespace A_0{
	vector<long long>tim[maxn+5];
	vector<int>id[maxn+5];
	void solve(){
		for(int i=1;i<=m;i++){
			tim[a[i].x].push_back(a[i].p);
//			if(a[i].x==37974){
//				printf("debug:%d %d\n",i,a[i].p);
//			}
			tim[a[i].y].push_back(a[i].q);
		}
		for(int i=1;i<=n;i++){
			sort(tim[i].begin(),tim[i].end());
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)tim[i].size();j++){
				cnt++;
				id[i].push_back(cnt);
			}
		}
		int s=0,t=cnt+1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)tim[i].size()-1;j++){
				add_edge(id[i][j],id[i][j+1],B*(tim[i][j+1]-tim[i][j]));
			}
		}
		for(int i=1;i<=m;i++){
			int x=a[i].x,y=a[i].y;
			int l=lower_bound(tim[x].begin(),tim[x].end(),a[i].p)-tim[x].begin();
			int r=lower_bound(tim[y].begin(),tim[y].end(),a[i].q)-tim[y].begin();
			add_edge(id[x][l],id[y][r],C);
			if(x==1){
				add_edge(s,id[x][l],B*a[i].p);
			}
			if(y==n){
				add_edge(id[y][r],t,a[i].q);
			}
		}
		dijkstra(s);
		printf("%lld\n",dist[t]);
	}
}
int main(){
//	freopen("route4.in","r",stdin);
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	scanf("%d %d %lld %lld %lld",&n,&m,&A,&B,&C);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld %lld",&a[i].x,&a[i].y,&a[i].p,&a[i].q);
	}
//	A_0::solve();
////	brute_force::solve();
	if(m<=4000){
		brute_force::solve();
	}else{
		A_0::solve();
	}
}
/*
4 3 0 2 3
1 2 2 3
2 3 5 7
3 4 7 9

26
*/
