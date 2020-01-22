#include <cstdio>

int main(void) {
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int res = a / 5 + b / 10 * 3 + c / 2;
	printf("%d\n", res);
	return 0;
}
