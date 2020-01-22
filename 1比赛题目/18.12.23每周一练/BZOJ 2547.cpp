#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxk 105
#define maxn 105
using namespace std;
int n,m,K,T;
int tot;
struct point {
	int x;
	int y;
	point() {

	}
	point(int xx,int yy) {
		x=xx;
		y=yy;
	}
} a[maxk],b[maxk];

queue<point>q;
int dist[maxk][maxk];
int h[maxk][maxk];
const int walkx[4]= {1,-1,0,0},walky[4]= {0,0,1,-1};
void bfs(int sx,int sy,int type) {
	while(!q.empty()) q.pop();
	point now,nex;
	memset(dist,0x3f,sizeof(dist));
	dist[sx][sy]=0;
	q.push(point(sx,sy));
	while(!q.empty()) {
		now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			nex.x=now.x+walkx[i];
			nex.y=now.y+walky[i];
			int len=0;
			if(nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=m) {
				//步兵为0，骑兵为1
				//0移动奇数次，变为1，移动偶数次，变为0
				//1移动奇数次，变为0，移动偶数次，变为1
				if(type^(dist[now.x][now.y]%2)) {
					if(h[now.x][now.y]<h[nex.x][nex.y]) len=1;
				} else {
					if(h[now.x][now.y]>h[nex.x][nex.y]) len=1;
				}
				if(dist[nex.x][nex.y]>dist[now.x][now.y]+len) {
					dist[nex.x][nex.y]=dist[now.x][now.y]+len;
					q.push(point(nex.x,nex.y));
				}
			}
		}
	}
}


void debug() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

struct edge {
	int from;
	int to;
	int next;
	int len;
} E[maxn*maxn*2];
int head[maxn*maxn];
int sz=0;
void add_edge(int u,int v,int w) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

void make_graph() {
	for(int i=1; i<=2*K; i++) {
		if(i<=K) bfs(a[i].x,a[i].y,0);
		else bfs(a[i].x,a[i].y,1);
//		debug();
		for(int j=1; j<=2*K+1; j++) {
			add_edge(i,j,dist[b[j].x][b[j].y]);
		}
	}
}

int vis[maxn*maxn];
int match[maxn*maxn];
int dfs(int x,int limit) {
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(!vis[y]&&E[i].len<=limit) {
			vis[y]=1;
			if(!match[y]||dfs(match[y],limit)) {
				match[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

int check(int x) {
	memset(match,0,sizeof(match));
	int ans=0;
	for(int i=1; i<=2*K; i++) {
		memset(vis,0,sizeof(vis));
		if(dfs(i,x)) ans++;
	}
	if(ans+x>=2*K) return 1;
	else return 0;
}

int bin_search() {
	int l=0,r=K*2;
	int ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	return ans;
}
int main() {
	int x,y,r;
	scanf("%d %d %d %d",&n,&m,&K,&T);
	for(int i=1; i<=2*K+1; i++) {
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	tot=0;
	for(int i=1; i<=T; i++) {
		scanf("%d %d %d",&x,&y,&r);
		for(int j=1; j<=r; j++) {
			b[++tot]=point(x,y);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&h[i][j]);
		}
	}
	make_graph();
	printf("%d\n",bin_search());
}
