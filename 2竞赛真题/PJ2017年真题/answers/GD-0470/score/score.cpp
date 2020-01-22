#include<cstdio>
#include<cstdlib>

int a,b,c;
int tot=0;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	tot=a/5+b*3/10+c/2;
	printf("%d",tot);
	return 0;
}
