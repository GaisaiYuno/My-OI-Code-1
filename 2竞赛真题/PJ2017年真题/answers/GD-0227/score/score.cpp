#include<cstdio>
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",(a*2+b*3+c*5)/10);
	fclose(stdin);fclose(stdout);
	return 0;
}
