#include<cstdio>
#include<cstdlib>

int a,b,c;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	double ans=a*0.2+b*0.3+c*0.5;
	printf("%.0lf",ans);
}
