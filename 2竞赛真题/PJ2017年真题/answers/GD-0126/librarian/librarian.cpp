#include <cstdio>
#include <algorithm>
using namespace std;
int n, q;
int book[1024];
struct data {
	int len;
	int code;
} custom[1024];
int getLast(int x, int scale) {
	int times = 1;
	for (int i = 2; i <= scale; i++) times *= 10;
	return x % times;
}
int getScale(int x) {
	int scale = 0;
	while (x > 0) {
		scale++;
		x /= 10;
	}
	return scale;
}
int main() {
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &book[i]);
	sort(book + 1, book + n + 1);
	for (int i = 1; i <= q; i++) scanf("%d %d", &custom[i].len, &custom[i].code);
	for (int i = 1; i <= q; i++) {
		bool found = false;
		for (int j = 1; j <= n; j++) 
			if (getLast(custom[i].code, custom[i].len) == getLast(book[j], custom[i].len) && getScale(book[j]) >= custom[i].len) {
				found = true;
				printf("%d\n", book[j]);
				break;
			}
		if (!found) printf("-1\n");
	}
	return 0;
}