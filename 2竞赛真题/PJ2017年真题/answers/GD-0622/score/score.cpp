#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a/=10;b/=10;c/=10;
	ans+=a*2+b*3+c*5;
	printf("%d",ans);
	return 0;
}
