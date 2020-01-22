#include <cstdio>
#include <algorithm>

using namespace std;

#define IMX 2147483647

int n = 0, d = 0, k = 0;
int Used[15];
int ans = IMX;

struct biu {
	int x, s;
} a[15];

int Find(int k, int n, int M, int m)
{
	if (k > n) {
		int tmp = 0;
		if (M >= ::k) {
			for (int i = 0; i < m; ++ i)
				tmp = max(tmp, abs(a[Used[i]].x - a[Used[i - 1]].x - d));
			ans = min(ans, tmp);
		}
		return 0;
	}
	Find(k + 1, n, M, m);
	Used[m] = k;
	Find(k + 1, n, M + a[k].s, m + 1);
	Used[m] = 0;
}

int main(void)
{
	freopen("jump.in",  "r",  stdin);
	freopen("jump.out", "w", stdout);
	scanf("%d%d%d", &n, &d, &k);
	for (int i = 1; i <= n; ++ i)
		scanf("%d%d", &a[i].x, &a[i].s);
	Find(1, n, 0, 0);
	printf("%d", (ans == IMX) ? -1 : ans);
	return 0;
}

