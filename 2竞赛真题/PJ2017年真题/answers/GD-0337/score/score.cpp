# include<cstdio>
using namespace std;
double a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%lf%lf%lf",&a,&b,&c);
	double ans = a * 0.2 + b * 0.3 + c * 0.5;
	printf("%.0lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
