#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	int a, b, c;
	double tot=0;
	scanf ("%d%d%d", &a, &b, &c);
	tot=double(a)*0.2+double(b)*0.3+double(c)*0.5;
	printf ("%d\n", int(tot));
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
