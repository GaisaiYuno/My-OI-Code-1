#include <cstdio>
#include <iostream>
#include <cstring>

int a,b,c;

using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	a/=10;b/=10;c/=10;
	int ans=2*a+3*b+5*c;
	printf("%d\n",ans);
	return 0;
}
