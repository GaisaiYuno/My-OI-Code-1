#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>

using namespace std;

int n, m, b_l;
string a[1010], b;

int main ()
{
	freopen ("librarian.in", "r", stdin);
	freopen ("librarian.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= m; i ++)
	{
		cin >> b_l >> b;
		int t = 0;
		int a_min = 999999999;
		for (int j = 1; j <= n; j ++)
		{
			int l = -1, c = 0;
			for (int k = a[j].length () - b_l; k < a[j].length (); k ++)
			{
				l ++;
				if (a[j][k] == b[l]) c ++;
			}
			if (c == l + 1 && l != -1)
			{
				t = 1;
				int a_num = 0;
				for (int k = 0; k < a[j].length (); k ++)
					a_num = a_num * 10 + (int (a[j][k]) - 48);
				if (a_num < a_min) a_min = a_num;
			}
		}
		if (t) cout << a_min << endl;
			else cout << -1 << endl;
	}
	return 0;
}
