#include<cstdio>
#include<cstring>
int main()
{
	freopen("score.in","r",stdin);
freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	a=a*20/100;
	b=b*30/100;
	c=c*50/100;
	printf("%d",a+b+c);
	return 0;
}
