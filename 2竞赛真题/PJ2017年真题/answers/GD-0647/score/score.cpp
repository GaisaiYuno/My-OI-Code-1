#include<cstdio>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,n;
	scanf(" %d %d %d",&a,&b,&c);
	n=a/10*2+b/10*3+c/10*5;
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
