#include<cstdio>
using namespace std;
int a,b,c,Sum=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a=(a/10.0)*2;
	b=(b/10.0)*3;
	c=(c/10.0)*5;
	Sum=a+b+c;
	printf("%d",Sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
