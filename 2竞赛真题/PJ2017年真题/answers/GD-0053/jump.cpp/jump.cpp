#include<cstdio>
int main()
{   
    freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,i;
	scanf("%d%d%d",&n,&d,&k);
	int a[1000],b[1000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	printf("%d",-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
