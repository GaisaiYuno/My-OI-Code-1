#include <cstdio>

using namespace std;

int main(void)
{
	freopen("score.in",  "r",  stdin);
	freopen("score.out", "w", stdout);
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", a * 2 / 10 + b * 3 / 10 + c * 5 / 10);
	return 0;
}

