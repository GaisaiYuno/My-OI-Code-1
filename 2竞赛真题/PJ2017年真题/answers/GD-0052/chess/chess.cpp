#include <cstdio>
#include <cstring>

using namespace std;

int m, n, x, y, z;
int chess[101][101];
int dis[101][101];

void bfs0(int x, int y);
void bfs1(int x, int y);
void bfs2(int x, int y, int color);

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	memset(chess, -1, sizeof(chess));
	memset(dis, 0x7f, sizeof(dis));
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			chess[i][j] = 2;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		chess[x][y] = z;
	}
	dis[1][1] = 0;
	if(chess[1][1] == 0)
	bfs0(1, 1);
	else
	bfs1(1, 1);
	int ans = -1;
	if(dis[m][m] == 2139062143)
	printf("%d", ans);
	else
	printf("%d", dis[m][m]);
	return 0;
}

void bfs0(int x, int y)
{
	if(chess[x + 1][y] == 0)
	{
		if(dis[x + 1][y] > dis[x][y])
		{
			dis[x + 1][y] = dis[x][y];
			bfs0(x + 1, y);
		}
	}
	else if(chess[x + 1][y] == 1)
	{
		if(dis[x + 1][y] > dis[x][y] + 1)
		{
			dis[x + 1][y] = dis[x][y] + 1;
			bfs1(x + 1, y);
		}	
	}
	else if(chess[x + 1][y] == 2)
	{
		if(dis[x + 1][y] > dis[x][y] + 2)
		{
			dis[x + 1][y] = dis[x][y] + 2;
			bfs2(x + 1, y, 0);
		}		
	}
	
	if(chess[x - 1][y] == 0)
	{
		if(dis[x - 1][y] > dis[x][y])
		{
			dis[x - 1][y] = dis[x][y];
			bfs0(x - 1, y);
		}	
	}
	else if(chess[x - 1][y] == 1)
	{
		if(dis[x - 1][y] > dis[x][y] + 1)
		{
			dis[x - 1][y] = dis[x][y] + 1;
			bfs1(x - 1, y);
		}		
	}
	else if(chess[x - 1][y] == 2)
	{
		if(dis[x - 1][y] > dis[x][y] + 2)
		{
			dis[x - 1][y] = dis[x][y] + 2;
			bfs2(x - 1, y, 0);
		}		
	}
	
	if(chess[x][y + 1] == 0)
	{
		if(dis[x][y + 1] > dis[x][y])
		{
			dis[x][y + 1] = dis[x][y];
			bfs0(x, y + 1);
		}	
	}
	else if(chess[x][y + 1] == 1)
	{
		if(dis[x][y + 1] > dis[x][y] + 1)
		{
			dis[x][y + 1] = dis[x][y] + 1;
			bfs1(x, y + 1);
		}		
	}
	else if(chess[x][y + 1] == 2)
	{
		if(dis[x][y + 1] > dis[x][y] + 2)
		{
			dis[x][y + 1] = dis[x][y] + 2;
			bfs2(x, y + 1, 0);
		}	
	}
	
	if(chess[x][y - 1] == 0)
	{
		if(dis[x][y - 1] > dis[x][y])
		{
			dis[x][y - 1] = dis[x][y];
			bfs0(x, y - 1);
		}	
	}
	else if(chess[x][y - 1] == 1)
	{
		if(dis[x][y - 1] > dis[x][y] + 1)
		{
			dis[x][y - 1] = dis[x][y] + 1;
			bfs1(x, y - 1);
		}	
	}
	else if(chess[x][y - 1] == 2)
	{
		if(dis[x][y - 1] > dis[x][y] + 2)
		{
			dis[x][y - 1] = dis[x][y] + 2;
			bfs2(x, y - 1, 0);
		}	
	}
}

void bfs1(int x, int y)
{
	if(chess[x + 1][y] == 1)
	{
		if(dis[x + 1][y] > dis[x][y])
		{
			dis[x + 1][y] = dis[x][y];
			bfs1(x + 1, y);
		}
	}
	else if(chess[x + 1][y] == 0)
	{
		if(dis[x + 1][y] > dis[x][y] + 1)
		{
			dis[x + 1][y] = dis[x][y] + 1;
			bfs0(x + 1, y);
		}	
	}
	else if(chess[x + 1][y] == 2)
	{
		if(dis[x + 1][y] > dis[x][y] + 2)
		{
			dis[x + 1][y] = dis[x][y] + 2;
			bfs2(x + 1, y, 1);
		}		
	}
	
	if(chess[x - 1][y] == 1)
	{
		if(dis[x - 1][y] > dis[x][y])
		{
			dis[x - 1][y] = dis[x][y];
			bfs1(x - 1, y);
		}	
	}
	else if(chess[x - 1][y] == 0)
	{
		if(dis[x - 1][y] > dis[x][y] + 1)
		{
			dis[x - 1][y] = dis[x][y] + 1;
			bfs0(x - 1, y);
		}		
	}
	else if(chess[x - 1][y] == 2)
	{
		if(dis[x - 1][y] > dis[x][y] + 2)
		{
			dis[x - 1][y] = dis[x][y] + 2;
			bfs2(x - 1, y, 1);
		}		
	}
	
	if(chess[x][y + 1] == 1)
	{
		if(dis[x][y + 1] > dis[x][y])
		{
			dis[x][y + 1] = dis[x][y];
			bfs1(x, y + 1);
		}	
	}
	else if(chess[x][y + 1] == 0)
	{
		if(dis[x][y + 1] > dis[x][y] + 1)
		{
			dis[x][y + 1] = dis[x][y] + 1;
			bfs0(x, y + 1);
		}		
	}
	else if(chess[x][y + 1] == 2)
	{
		if(dis[x][y + 1] > dis[x][y] + 2)
		{
			dis[x][y + 1] = dis[x][y] + 2;
			bfs2(x, y + 1, 1);
		}	
	}
	
	if(chess[x][y - 1] == 1)
	{
		if(dis[x][y - 1] > dis[x][y])
		{
			dis[x][y - 1] = dis[x][y];
			bfs1(x, y - 1);
		}	
	}
	else if(chess[x][y - 1] == 0)
	{
		if(dis[x][y - 1] > dis[x][y] + 1)
		{
			dis[x][y - 1] = dis[x][y] + 1;
			bfs0(x, y - 1);
		}	
	}
	else if(chess[x][y - 1] == 2)
	{
		if(dis[x][y - 1] > dis[x][y] + 2)
		{
			dis[x][y - 1] = dis[x][y] + 2;
			bfs2(x, y - 1, 1);
		}	
	}
}

void bfs2(int x, int y, int color)
{
if(color == 0)
{
		if(chess[x + 1][y] == 0)
	{
		if(dis[x + 1][y] > dis[x][y])
  		{
			dis[x + 1][y] = dis[x][y];
			bfs0(x + 1, y);
		}
	}
	else if(chess[x + 1][y] == 1)
	{
		if(dis[x + 1][y] > dis[x][y] + 1)
		{
			dis[x + 1][y] = dis[x][y] + 1;
			bfs1(x + 1, y);
		}	
	}
	
	if(chess[x - 1][y] == 0)
	{
		if(dis[x - 1][y] > dis[x][y])
		{
			dis[x - 1][y] = dis[x][y];
			bfs0(x - 1, y);
		}	
	}
	else if(chess[x - 1][y] == 1)
	{
		if(dis[x - 1][y] > dis[x][y] + 1)
		{
			dis[x - 1][y] = dis[x][y] + 1;
			bfs1(x - 1, y);
		}		
	}
	
	if(chess[x][y + 1] == 0)
	{
		if(dis[x][y + 1] > dis[x][y])
		{
			dis[x][y + 1] = dis[x][y];
			bfs0(x, y + 1);
		}	
	}
	else if(chess[x][y + 1] == 1)
	{
		if(dis[x][y + 1] > dis[x][y] + 1)
		{
			dis[x][y + 1] = dis[x][y] + 1;
			bfs1(x, y + 1);
		}		
	}
	
	if(chess[x][y - 1] == 0)
	{
		if(dis[x][y - 1] > dis[x][y])
		{
			dis[x][y - 1] = dis[x][y];
			bfs0(x, y - 1);
		}	
	}
	else if(chess[x][y - 1] == 1)
	{
		if(dis[x][y - 1] > dis[x][y] + 1)
		{
			dis[x][y - 1] = dis[x][y] + 1;
			bfs1(x, y - 1);
		}	
	}

}
if(color == 1)
{
		if(chess[x + 1][y] == 1)
	{
		if(dis[x + 1][y] > dis[x][y])
		{
			dis[x + 1][y] = dis[x][y];
			bfs1(x + 1, y);
		}
	}
	else if(chess[x + 1][y] == 0)
	{
		if(dis[x + 1][y] > dis[x][y] + 1)
		{
			dis[x + 1][y] = dis[x][y] + 1;
			bfs0(x + 1, y);
		}	
	}
	
	if(chess[x - 1][y] == 1)
	{
		if(dis[x - 1][y] > dis[x][y])
		{
			dis[x - 1][y] = dis[x][y];
			bfs1(x - 1, y);
		}	
	}
	else if(chess[x - 1][y] == 0)
	{
		if(dis[x - 1][y] > dis[x][y] + 1)
		{
			dis[x - 1][y] = dis[x][y] + 1;
			bfs0(x - 1, y);
		}		
	}
	
	if(chess[x][y + 1] == 1)
	{
		if(dis[x][y + 1] > dis[x][y])
		{
			dis[x][y + 1] = dis[x][y];
			bfs1(x, y + 1);
		}	
	}
	else if(chess[x][y + 1] == 0)
	{
		if(dis[x][y + 1] > dis[x][y] + 1)
		{
			dis[x][y + 1] = dis[x][y] + 1;
			bfs0(x, y + 1);
		}		
	}
	
	if(chess[x][y - 1] == 1)
	{
		if(dis[x][y - 1] > dis[x][y])
		{
			dis[x][y - 1] = dis[x][y];
			bfs1(x, y - 1);
		}	
	}
	else if(chess[x][y - 1] == 0)
	{
		if(dis[x][y - 1] > dis[x][y] + 1)
		{
			dis[x][y - 1] = dis[x][y] + 1;
			bfs0(x, y - 1);
		}	
	}
}
}
