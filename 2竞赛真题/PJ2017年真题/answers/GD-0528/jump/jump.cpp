#include<cstdio>
using namespace std;
int sum=0;
int x,n,d,k;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	int ba;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&ba,&x);
		if(x>0) sum+=x;
	}
	if(sum<k) printf("-1");
	else printf("2");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
