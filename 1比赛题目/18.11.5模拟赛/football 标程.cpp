#include <bits/stdc++.h>
using namespace std;
#define N 1050
#define pii pair<ll,int>
#define mp make_pair
#define ll long long
#define int long long
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

struct edge {int nex,to,dis;}e[10001000];
int n,m,k,A,B,C;
int x,y,he,tail,cnt,tmp;
pii q[N*N];
int d[N][N],vis[N][N],head[N*N*5],id[N][N][5],mark[N*N*5];
ll dis[N*N*5];
priority_queue<pii,vector<pii>,greater<pii> > heap;

void add(int x,int y,int z) {
	printf("%d %d %d\n",x+1,y+1,z); 
e[++cnt].to=y; e[cnt].nex=head[x]; e[cnt].dis=z; head[x]=cnt;}

void dijks()
{
	memset(dis,0x3f,sizeof(dis));
	int st=id[q[1].first][q[1].second][4];
	heap.push(mp(0,st));
	dis[st]=0;
	while (!heap.empty()) {
		int x=heap.top().second; heap.pop();
		if (mark[x]) continue;
		mark[x]=1;
		for (int i=head[x];i;i=e[i].nex) {
			int v=e[i].to;
			if (dis[x]+e[i].dis<dis[v]) {
				dis[v]=dis[x]+e[i].dis;
				heap.push(mp(dis[v],v));
			}
		}
	}
}

signed main()
{
	freopen("debug2.txt","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&n,&m,&A,&B,&C);
	scanf("%lld",&k);
	for (int i=1;i<=k;i++) {
		scanf("%lld%lld",&x,&y);
		q[++tail]=mp(x,y);
		d[x][y]=0; vis[x][y]=1;
	}
	while (he<tail) {
		int x=q[++he].first,y=q[he].second;
		for (int i=0;i<4;i++) {
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if (nx<0 || nx>n || ny<0 || ny>m) continue;
			if (!vis[nx][ny]) {d[nx][ny]=d[x][y]+1; vis[nx][ny]=1; q[++tail]=mp(nx,ny);}
		}
	}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
			for (int k=0;k<=4;k++)
				id[i][j][k]=++tmp;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			for (int k=0;k<4;k++) {
				add(id[i][j][4],id[i][j][k],B);
				add(id[i][j][k],id[i][j][4],C*d[i][j]);
			}
			for (int k=0;k<4;k++) {
				int nx=i+dir[k][0],ny=j+dir[k][1];
				if (nx<0 || nx>n || ny<0 || ny>m) continue;
				add(id[i][j][k],id[nx][ny][k],A);
				add(id[i][j][4],id[nx][ny][4],C);
			}
		}
	//for (int i=1;i<=tmp;i++) printf("%lld\n",dis[i]);
	dijks();
	printf("%lld\n",dis[id[q[k].first][q[k].second][4]]);
	return 0;
}
