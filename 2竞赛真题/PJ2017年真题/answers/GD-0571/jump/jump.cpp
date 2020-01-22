#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef long long ll;

int n, d, k;
ll zh = 0;
int a[500010], b[500010];
int now = 0;
ll ans = -1;

int main()
{
	freopen ("jump.in", "r", stdin);
	freopen ("jump.out", "w", stdout);
	scanf ("%d%d%d", &n, &d, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d%d", &a[i], &b[i]);
		if (b[i] > 0)
			zh += b[i];
	}
	if (zh < k)
	{
		printf ("-1");
		return 0;
	}
	for (ll mid = 0; ; ++mid)
	{
		zh = 0; now = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] - now < d - mid || a[i] - now > d + mid)	
				break;
			zh += a[i]; now = a[i];
		}
		if (zh >= k)
		{
			printf ("%lld", mid);
			return 0;
		}
	}
	return 0;
}
