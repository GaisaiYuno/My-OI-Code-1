#include<cstdio>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a=a/10*2;
	b=b/10*3;
	c=c/10*5;
	ans=a+b+c;
//	printf("%d %d %d\n",a,b,c);
	printf("%d",ans);
	return 0;
}
