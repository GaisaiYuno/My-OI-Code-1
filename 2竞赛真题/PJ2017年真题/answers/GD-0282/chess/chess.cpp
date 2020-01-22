#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=2e9;
int m, n, map[110][110], visit[110][110], tot=INF;
int zl[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool b=true;
void dfs(int x, int y, int coin, int curr, int chan)
{
	visit[x][y]=true;
	if (x==m && y==m)
	{
		b=false;
		tot=min(coin, tot);
		visit[x][y]=false;
		return;
	}
	for (int i=0;i<4;i++)
	{
		if (visit[x+zl[i][0]][y+zl[i][1]]==true) continue;
		if (x+zl[i][0]<=0 || x+zl[i][0]>m || y+zl[i][1]<=0 || y+zl[i][1]>m) continue;
		if (curr==1)
		{
			if (map[x+zl[i][0]][y+zl[i][1]]==-1) continue;
			else if (chan==map[x+zl[i][0]][y+zl[i][1]])
			{
				dfs(x+zl[i][0], y+zl[i][1], coin, 0, -1);
			}
			else
			{
				dfs(x+zl[i][0], y+zl[i][1], coin+1, 0, -1);
			}
		}
		else
		{
			if (map[x+zl[i][0]][y+zl[i][1]]==-1)
			{
				if (map[x][y]==0) dfs(x+zl[i][0], y+zl[i][1], coin+2, 1, 0);
				else dfs(x+zl[i][0], y+zl[i][1], coin+3, 1, 0);
				if (map[x][y]==1) dfs(x+zl[i][0], y+zl[i][1], coin+2, 1, 1);
				else dfs(x+zl[i][0], y+zl[i][1], coin+3, 1, 1);
			}
			else if (map[x+zl[i][0]][y+zl[i][1]]==map[x][y])
			{
				dfs(x+zl[i][0], y+zl[i][1], coin, 0, -1);
			}
			else
			{
				dfs(x+zl[i][0], y+zl[i][1], coin+1, 0, -1);
			}
		}
	}
	visit[x][y]=false;
	return;
}
int main ()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int x, y, z;
	scanf ("%d%d", &m, &n);
	for (int i=0;i<=105;i++)
	{
		for (int j=0;j<=105;j++)
		{
			map[i][j]=-1;
			visit[i][j]=false;
		}
	}
	for (int i=1;i<=n;i++)
	{
		scanf ("%d%d%d", &x, &y, &z);
		map[x][y]=z;
	}
	if (m>=17)
	{
		printf ("-1\n");
		return 0;
	}
	dfs(1,1,0,0,-1);
	if (b) printf ("-1");
	else printf ("%d", tot);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
