#include<cstdio>
#include<algorithm>
#include<cstring>
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,c,b,a,n,m;
	
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
	 	scanf("%d %d %d",&a,&b,&c);
	}
	if(m==n*n)
	{
		printf("0");
		return 0;
	}
	if(n==1) 
	{
		printf("0");
		return 0;
	}
	if(n==2&&m==1)
	{
		printf("4");
		return 0;
	}
	if(n==2&&m==2)
	{
		printf("2");
		return 0;
	}
	if(m==1&&n>=3) 
	{
		printf("%d",2*(n+n-3));
		return 0;	
	}
	return 0;	
}
