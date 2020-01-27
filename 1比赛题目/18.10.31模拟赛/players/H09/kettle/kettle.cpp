#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=2005;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

struct building{
	int x,y;
} bd[maxn];

int n,m,cnt,req;
char a[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];

struct data{
	int x,y,cst;
};
queue<data> q;
int bfs(int st,int en)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	int sx=bd[st].x,sy=bd[st].y,ex=bd[en].x,ey=bd[en].y;
	q.push((data){sx,sy,0});
	dis[sx][sy]=0; vis[sx][sy]=1;
	
	data u,v;
	while (!q.empty())
	{
		u=q.front(); q.pop(); vis[u.x][u.y]=false;
		int nx,ny,ncst;
		for (int i=0; i<4; i++)
		{
			nx=u.x+dx[i],ny=u.y+dy[i];
			if (nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]!='#')
			{
				ncst=u.cst+(a[nx][ny]=='.');
				if (ncst<dis[nx][ny])
				{
					dis[nx][ny]=ncst;
					if (!vis[nx][ny])
					{
						vis[nx][ny]=true;
						q.push((data){nx,ny,ncst});
					}
				}
			}
		}
	}
	return dis[ex][ey];
}

int main()
{
	freopen("kettle.in","r",stdin);
	freopen("kettle.out","w",stdout);
	
	scanf("%d%d%d%d",&n,&m,&cnt,&req);
	for (int i=1; i<=n; i++)
		scanf("%s",a[i]+1);
		
	int x,y;
	for (int i=1; i<=cnt; i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]='b';
		bd[i].x=x; bd[i].y=y;
	}
	
	for (int i=1; i<=req; i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",bfs(x,y));
	}
	
	return 0;
}
