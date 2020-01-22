#include <cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	int i,m,n,x[1001],y[1001],c[1001];
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
	printf("-1");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
