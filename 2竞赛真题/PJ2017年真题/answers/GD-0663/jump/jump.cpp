#include <cstdio>
#include <cstring>

const int N = 500007;
int n, d, k, l, r, ans = -1, mxdis = 0;
int dis[N], a[N], f[N], p[N];

int check(int m)
{
	int ret = -2147483647, mi = m >= d ? 1 : d - m, mx = d + m;
	memset(f, 0, sizeof(f));
	memset(p, 0, sizeof(p));
	for (int i = 1; i <= n; i++)
	{
		int mxf = -2147483647, mxid = 0;
		for (int j = 0; j < i; j++)
			if (dis[j] + mx >= dis[i] && dis[j] + mi <= dis[i] && !p[j])
			{
				if (f[j] > mxf)
					mxf = f[j];
				mxid = 1;
			}
		if (mxid == 0)
			p[i] = 1;
		else
		{
			f[i] = mxf + a[i];
			p[i] = 0;
			if (f[i] > ret)
				ret = f[i];
		}
	}
	if (ret >= k)
		return 1;
	else
		return 0;
}

int main()
{
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);

	scanf("%d%d%d", &n, &d, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &dis[i], &a[i]);
		if (dis[i] > mxdis)
			mxdis = dis[i];
	}
	l = 0, r = mxdis;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1, ans = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
