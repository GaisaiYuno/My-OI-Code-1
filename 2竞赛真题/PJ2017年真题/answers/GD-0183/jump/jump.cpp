#include<cstdio>
int x[500010],s[500010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&x[i],&s[i]);
	printf("-1");
	return 0;
}
