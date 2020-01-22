#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1006, maxnum = 10000006;

int n, q, num[maxn], len, f;
int mod;
int found[maxnum];

int main() {
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);

	scanf("%d%d", &n, &q);

	for (int i = 1; i < maxnum; ++i)
		found[i] = -1;

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num[i]);
		mod = 10;
		while (mod / 10 <= num[i]) {
			if (found[num[i] % mod] == -1 || found[num[i] % mod] > num[i])
				found[num[i] % mod] = num[i];
			mod *= 10;
		}
	}

	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &len, &f);
		printf("%d\n", found[f]);
	}

	return 0;
}
