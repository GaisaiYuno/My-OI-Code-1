#include<cstdio>
int a,b,c;
int main(void)
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	printf("%.0lf",a*0.2+b*0.3+c*0.5);
	return 0;
}
