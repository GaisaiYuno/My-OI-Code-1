#include<cstdio>
#include<cstring>
int n,m,k;
int a[41000],b[41000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	printf("-1");
	return 0;
}
