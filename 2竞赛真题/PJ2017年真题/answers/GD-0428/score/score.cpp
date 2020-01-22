#include<cstdio>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a*=0.2;
	b*=0.3;
	b++;
	c*=0.5;
	ans=a+b+c;
	printf("%d",ans);
	return 0;
}
