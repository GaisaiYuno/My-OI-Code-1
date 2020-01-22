#include<cstdio>

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int d=a/5+b/10*3+c/2;
	printf("%d",d);
	return 0;
}
