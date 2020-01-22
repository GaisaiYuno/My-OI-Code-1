#include<cstdio>
int s[100000000];
int main()
{
	int n,d,k,x;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		scanf("%d",&s[x]);
		if(s[x]>0) sum+=s[x];
	}
	if(sum<k)
	{
		printf("-1\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
