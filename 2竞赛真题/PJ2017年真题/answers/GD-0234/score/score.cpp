#include<cstdio>
#include<cstring>
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	a=a/10*2;
	b=b/10*3;
	c=c/10*5;
	printf("%d",a+b+c);
	return 0;
}
