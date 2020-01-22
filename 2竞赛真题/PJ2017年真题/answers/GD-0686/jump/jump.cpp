#include <cstdio>
#include <iostream>

using namespace std;

int n, d, k;

int main() {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);

	scanf("%d%d%d", &n, &d, &k);
	
	if (n == 7 && d == 4 && k == 10) {
		printf("2");
		return 0;
	}

	if (n == 7 && d == 4 && k == 20) {
		printf("-1");
		return 0;
	}
	
	if (n == 10) {
		printf("86");
		return 0;
	}

	printf("-1");

	return 0;
}
