#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	a/=10;
	a*=2;
	b/=10;
	b*=3;
	c/=10;
	c*=5;
	ans=a+b+c;
	printf("%d",ans);
}
