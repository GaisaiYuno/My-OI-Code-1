#include<cstdio>
using namespace std;
#define maxlongint 0x7fffffff
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,c[101][101],f[101][101];
void dfs(int x,int y,int cost,int X,int Y)
{
	if(f[x][y]<=cost) return;
	f[x][y]=cost;
	int i,xx,yy;
	for(i=0;i<4;i++)
	{
		xx=x+dx[i];yy=y+dy[i];
		if(xx>0&&yy>0&&xx<=n&&yy<=n)
		{
			if(c[x][y]==0)
			{
				if(c[xx][yy]==0) continue;
				else
				{
					if(c[X][Y]==c[xx][yy])
					{
						dfs(xx,yy,cost,1,1);
					}
					else dfs(xx,yy,cost+1,1,1);
				}
			}
			else
			{
				if(c[xx][yy]==0)
				{
					dfs(xx,yy,cost+2,x,y);
				}
				else
				{
					if(c[x][y]==c[xx][yy])
					{
						dfs(xx,yy,cost,1,1);
					}
					else dfs(xx,yy,cost+1,1,1);
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,i,j,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		c[x][y]=z+1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			f[i][j]=maxlongint;
		}
	}
	dfs(1,1,0,1,1);
	if(f[n][n]==maxlongint) printf("-1\n");
	else printf("%d\n",f[n][n]);
	return 0;
}
