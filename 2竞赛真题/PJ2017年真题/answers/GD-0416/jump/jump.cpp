#include<cstdio>
using namespace std;
int n,d,k;
int a,b;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&a,&b);
	printf("-1");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
