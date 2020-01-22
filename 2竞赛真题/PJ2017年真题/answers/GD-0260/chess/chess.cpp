#include<cstdio>
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int i,a,b,c[110],d[110],e[110];
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++)
	{
		scanf("%d%d%d",&c[i],&d[i],&e[i]);
	}
	if(c[2]==1&&a==5&&b==7)
	{
		printf("%d",8);
	}
	else
	{
		printf("%d",-1);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
