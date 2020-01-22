#include<cstdio>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",int(a/5+b/10*3+c/2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
