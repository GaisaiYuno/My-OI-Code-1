#include <iostream>
#include <cstdio>

using namespace std;

long n, m, d, c, a[500010], b[500010];

bool check (int d_g)
{
	int j = 1, k = 0, s = 0;
	while (k + d_g <= a[n])
	{
//		cout << k << "-" << k + d_g << "-" << j << "-" << b_max << endl;
//		getchar ();
		int b_max = -999999999;
		for (int i = j; i <= n; i ++)
		{
			if (a[i] > k + d_g) break;
			if (a[i] < k + d_g && b[i] > b_max)
			{
				b_max = b[i];
				k = a[i];
				j = i + 1;
			}
		}
		if (a[j] >= k + d_g) break;
		s += b_max;
	}
	if (s < c) return 1;
	else return 0;
}

int main ()
{
	freopen ("jump.in", "r", stdin);
	freopen ("jump.out", "w", stdout);
	cin >> n >> d >> c;
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%lld %lld", &a[i], &b[i]);
		if (b[i] > 0) m += b[i];
	}
	int x = -1, y = a[n] + 1;
	while (x + 1 < y)
	{
		int z = (x + y) / 2;
//		cout << "z = " << z << endl;
//		getchar ();
		if (check (z)) x = z;
			else y = z;
	}
	//?????????????????????????????
	if (m < c)
	{
		cout << -1;
		return 0;
	}
	//????????????????????????????
//	cout << y << " " << d << endl;
	if (y >= d) cout << y - d;
		else cout << 0;
	return 0;
}
