#include<cstdio>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	a<=100&&a>=0;
	b<=100&&b>=0;
	c<=100&&c>=0;
	d=a*0.2+b*0.3+c*0.5;
	printf("%d",d);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
