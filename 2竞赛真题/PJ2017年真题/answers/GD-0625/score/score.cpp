#include<cstdio>

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a=0,b=0,c=0;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",a*1/10*2+b/10*3+c/10*5);
	fclose(stdin);fclose(stdout);
	return 0;
}
