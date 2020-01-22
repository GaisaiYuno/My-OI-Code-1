#include <cstdio>
#include <cstring>

const int N = 107, INF = 666666666;
const int D[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[N][N], f[N][N];
int ans = INF, n, m, x, y, c;

int hf(int x, int y) { return (x <= n && x > 0 && y <= n && y > 0); }

void dfs(int x, int y, int val, int tag)
{
	if (x == n && y == n && val < ans)
	{
		ans = val;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int dx = x + D[i][0], dy = y + D[i][1];
		if (hf(dx, dy))
		{
			if (a[dx][dy] == 0)
			{
				if (val + 2 < f[dx][dy] && tag)
				{
					a[dx][dy] = a[x][y];
					f[dx][dy] = val + 2;
					dfs(dx, dy, val + 2, 0);
					a[dx][dy] = 0;
				}
			}
			if (a[dx][dy] == a[x][y])
			{
				if (val < f[dx][dy])
				{
					f[dx][dy] = val;
					dfs(dx, dy, val, 1);
				}
			}
			if ((a[x][y] == 1 && a[dx][dy] == 2) || (a[x][y] == 2 && a[dx][dy] == 1))
			{
				if (val + 1 < f[dx][dy])
				{
					f[dx][dy] = val + 1;
					dfs(dx, dy, val + 1, 1);
				}
			}
		}
	}
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);

	memset(a, 0, sizeof(a));
	memset(f, 0x3f, sizeof(f));

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &c);
		a[x][y] = c + 1;
	}
	f[1][1] = 0;
	dfs(1, 1, 0, 1);
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
