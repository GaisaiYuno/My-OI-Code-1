#include<cstdio>
#include<cstdlib>
#include<cstring>

int a,b,c,ans=0;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	ans=a*20/100+b*30/100+c*50/100;
	printf("%d",ans);
	return 0;
}
