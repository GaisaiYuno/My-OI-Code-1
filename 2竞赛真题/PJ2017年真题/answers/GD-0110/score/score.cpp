#include<cstdio>
#include<cstring>
using namespace std;

int a,b,c;
int ans;

int main(void)
{
	
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	scanf("%d%d%d",&a,&b,&c);
	
	a=a/10;a*=2;
	b=b/10;b*=3;
	c=c/10;c*=5;
	
	ans=a+b+c;
	
	printf("%d\n",ans);
	
	return 0;
}
