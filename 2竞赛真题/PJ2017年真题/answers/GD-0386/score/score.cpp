#include <cstdio>

using namespace std;
int a, b, c;
int final;

int main () {
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	
	scanf("%d%d%d", &a, &b, &c);
	
//	final = a*0.2 + b*0.3 + c*0.5;
	final = (a*2 + b*3 + c*5) / 10;
	
	printf("%d", final);
	
	return 0;
}
