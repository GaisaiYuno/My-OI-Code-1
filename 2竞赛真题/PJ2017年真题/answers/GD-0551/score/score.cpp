#include<cstdio>
#include<cstring>

int a,b,c;
double ans=0;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	//a*=0.2;b*=0.3;c*=0.5;
	ans=a*0.2+b*0.3+c*0.5;
	printf("%.0lf",ans);
}
