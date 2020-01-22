#include <cstdio>
#include <algorithm>

using namespace std;

const int num[10] = {1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
int n, m;
const int MAXN = 1010;
int a[MAXN];

int main(void) {
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for(int i = 0; i < m; ++i) {
		int l, x;
		bool f = 0;
		scanf("%d%d", &l, &x);
		for(int j = 0; j < n; ++j) {
			if(a[j] % num[l] == x) {
				printf("%d\n", a[j]);
				f = 1;
				break;
			}
		}
		if(!f) {
			printf("-1\n");
		}
	}
	return 0;
}

