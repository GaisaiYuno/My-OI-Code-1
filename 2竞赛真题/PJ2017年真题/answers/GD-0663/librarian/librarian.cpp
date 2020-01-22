#include <cstdio>
#include <cstring>

const int N = 1007, INF = 2147483647;
int n, q, a, b, ans;
int num[N], p[N], t[N];

int main()
{
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	while (q--)
	{
		memset(p, 0, sizeof(p));
		memcpy(t, num, sizeof(num));
		ans = INF;
		scanf("%d%d", &a, &b);
		while (b != 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (t[i] % 10 != b % 10)
					p[i] = 1;
				t[i] /= 10;
			}
			b /= 10;
		}
		for (int i = 1; i <= n; i++)
			if (!p[i] && num[i] < ans)
				ans = num[i];
		if (ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
