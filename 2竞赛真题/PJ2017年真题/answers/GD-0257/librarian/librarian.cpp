#include <cstdio>
#include <algorithm>

using namespace std;

int books[1005];

int tpow(int n)
{
	int tmp = 1;
	for (int i = 1; i <= n; ++ i)
		tmp *= 10;
	return tmp;
}

int main(void)
{
	freopen("librarian.in",  "r",  stdin);
	freopen("librarian.out", "w", stdout);
	int n = 0, q = 0;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &books[i]);
	sort(books + 1, books + 1 + n);
	for (int i = 1; i <= q; ++ i) {
		int m = 0, s = 0;
		scanf("%d%d", &m, &s);
		int modn = tpow(m);
		bool flag = 1;
		for (int j = 1; j <= n; ++ j)
			if (books[j] % modn == s) {
				printf("%d\n", books[j]);
				flag = 0;
				break;
			}
		if (flag)
			puts("-1");
	}
	return 0;
}
