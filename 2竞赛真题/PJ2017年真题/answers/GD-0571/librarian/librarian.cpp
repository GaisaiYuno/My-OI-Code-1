#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, q;
int pows[12] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int a[1010];
int lena[1010];
int b[1010];
int lenb[1010];
bool tf;

void qsort (int l, int r)
{
	int i = l, j = r, m = a[l], t;
	while (i <= j)
	{
		while (a[i] < m) ++i;
		while (a[j] > m) --j;
		if (i <= j)
		{
			t = a[i]; a[i] = a[j]; a[j] = t;
			t = lena[i]; lena[i] = lena[j]; lena[j] = t;
			++i; --j;
		}
	}
	if (i < r) qsort (i, r);
	if (l < j) qsort (l, j);
}
bool check (int x, int y)
{
	if (lena[x] < lenb[y])
		return 0;
	if ((a[x] - b[y]) % pows[lenb[y]])
		return 0;
	return 1;
}

int main()
{
	freopen ("librarian.in", "r", stdin);
	freopen ("librarian.out", "w", stdout);
	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d", &a[i]);
		lena[i] = 9;
		while (a[i] < pows[lena[i] - 1])
			--lena[i];
	}
	qsort (1, n);
	for (int i = 1; i <= q; ++i)
	{
		tf = 1;
		scanf ("%d%d", &lenb[i], &b[i]);
		for (int j = 1; j <= n; ++j)
			if (check (j, i))
			{
				printf ("%d\n", a[j]);
				tf = 0; break;
			}
		if (tf)
			printf ("-1\n");
	}
	return 0;
}
