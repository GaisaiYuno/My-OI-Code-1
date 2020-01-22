#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
using namespace std;
int main()
{	int a, b, c;
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", a/5+b/10*3+c/2);
	return 0;
}
