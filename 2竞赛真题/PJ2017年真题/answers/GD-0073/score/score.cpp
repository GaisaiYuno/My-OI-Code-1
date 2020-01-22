#include <cstdio>

int a,b,c;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	int d=a*2/10+b*3/10+c*5/10;
	printf("%d",d);
	return 0;
}
