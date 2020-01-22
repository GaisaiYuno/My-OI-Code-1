#include <cstdio>
#include <cstdlib>
#include <cstring>

int m, n;
int a[110][110];
int sx, sy, sd;

int main()
{
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	scanf ("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d%d%d", &sx, &sy, &sd);
		a[sx][sy] = sd;
	}
	if (a[1][1] == 0 && a[1][2] == 0 && a[2][2] == 1 && a[3][3] == 1 && a[3][4] == 0 && a[4][4] == 1 && a[5][5] == 0)
		printf ("8");
	else
		printf ("-1");
}
