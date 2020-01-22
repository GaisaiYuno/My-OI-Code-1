#include<cstdio>
using namespace std;
double a,b,c;
double f[4];
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%lf%lf%lf",&a,&b,&c);
	f[1]=a/5;
	f[2]=b/100*30;
	f[3]=c/2;
	printf("%.0lf\n",f[1]+f[2]+f[3]);
	return 0;
}
