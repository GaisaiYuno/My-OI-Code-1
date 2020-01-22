#include <cstdio>

int a, b, c, ans;

int main()
{
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);

	scanf("%d%d%d", &a, &b, &c);
	ans = a / 5 + b * 3 / 10 + c / 2;
	printf("%d\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
