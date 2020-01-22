#include <iostream>
#include <cstdio>

using namespace std;

int n, m, x, y, z, a[1010][1010], b[1010][1010], a_m_min = 999999999;

void Tpick (int a_x, int a_y, int a_c, int a_m)
{
	if (b[a_x][a_y])
	{
		a_m = 0;
		return;
	}
	if (a_x < 0 || a_y < 0 || a_x > n || a_y > n)
	{
		a_m = 0;
		return;
	}
	if (a_x == n && a_y == n)
	{
		if (a_m < a_m_min) a_m_min = a_m;
		a_m = 0;
		return;
	}
	if (a[a_x][a_y] == 0 && a_c == 0)
	{
		a_m = 0;
		return;
	}
	if (a[a_x][a_y] != a_c && a[a_x][a_y] != 0) a_m = a_m + 1;
	if (a[a_x][a_y] == 0) a_m = a_m + 2;
	b[a_x][a_y] = 1;
	Tpick (a_x - 1, a_y, a[a_x][a_y], a_m);
	Tpick (a_x, a_y - 1, a[a_x][a_y], a_m);
	Tpick (a_x, a_y + 1, a[a_x][a_y], a_m);
	Tpick (a_x + 1, a_y, a[a_x][a_y], a_m);
	return;
}

int main ()
{
	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		cin >> x >> y >> z;
		a[x][y] = z + 1;
	}
	Tpick (1, 1, a[1][1], 0);
	if (a_m_min != 999999999) cout << a_m_min;
		else cout << -1;
	return 0;
}
