#include<cstdio>
using namespace std;
int a[1001][9],b[9];
inline int read()
{
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int x=0;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n=read(),m=read();
	int i,j,k,tot1=0;
	for(i=1;i<=n;i++)
	{
		int u=read(),tot1=0;
		a[i][0]=u;
		while(u>0)
		{
			a[i][++tot1]=u%10;
			u/=10;
		}
	}
	for(i=1;i<=m;i++)
	{
		int u=read(),v=read();
		int min1=0x7fffffff,tot1=0;
		for(k=1;k<=u;k++)
		{
			b[++tot1]=v%10;
			v/=10;
		}
		for(j=1;j<=n;j++)
		{
			bool p=0;
			for(k=1;k<=u;k++)
			if(b[k]!=a[j][k])
			{
				p=1;
				break;
			}
			if(!p&&min1>a[j][0])min1=a[j][0];
		}
		if(min1!=0x7fffffff)
		printf("%d\n",min1);
		else
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
