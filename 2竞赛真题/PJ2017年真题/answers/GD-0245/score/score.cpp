#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	float ans;
	scanf("%d%d%d",&a,&b,&c);
	ans=0.2*a+0.3*b+0.5*c;
	printf("%.f",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
