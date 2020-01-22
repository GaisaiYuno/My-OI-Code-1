#include<cstdio>

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a=1,b=1,c=1;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",a*0.2+b*0.3+c*0.5);
	return 0;
}
