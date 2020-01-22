#include<cstdio>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%.0lf\n",a*0.2+b*0.3+c*0.5);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
