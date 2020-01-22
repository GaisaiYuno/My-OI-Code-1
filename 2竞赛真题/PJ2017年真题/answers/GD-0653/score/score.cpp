#include<cstdio>
#include<cstdlib>
#include<cstring>
int a,b,c;
double a1,b1,c1;
double ans;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	a1=a*1.0,b1=b*1.0,c1=c*1.0;
	ans=a1*0.2+b1*0.3+c1*0.5;
	printf("%.0lf",ans);
	return 0;
}
