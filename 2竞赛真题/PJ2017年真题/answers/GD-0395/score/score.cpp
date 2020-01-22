#include<cstdio>
using namespace std;
int n,m,k;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	printf("%d",n/5+m*3/10+k/2);
	return 0;
}
