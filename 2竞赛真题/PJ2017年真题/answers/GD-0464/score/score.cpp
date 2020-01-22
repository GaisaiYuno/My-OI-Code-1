#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int a, b, c, ans = 0;

int main() {
	
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	
	scanf("%d %d %d", &a, &b, &c);
	
	a=a/10*2, b=b/10*3, c=c/10*5;
	
	ans = a+b+c;
	
	printf("%d\n", ans);
	
	return 0;
}
