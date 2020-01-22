#include <cstdio>
#include <iostream>

using namespace std;

int A, B, C;

int main() {
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);

	scanf("%d%d%d", &A, &B, &C);
	printf("%d", (A * 20 + B * 30 + C * 50) / 100);

	return 0;
}
