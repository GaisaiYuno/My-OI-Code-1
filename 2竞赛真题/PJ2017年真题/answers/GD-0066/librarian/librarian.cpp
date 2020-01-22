#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1001],b[1001],c[1001],n,m,d[1001],f[1001],e[1001],g[1001];
int cmp(int x,int y)
{
	if(x>y)return 1;
	else return 0;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[i]=a[i];
		while(g[i]!=0)
		{
			e[i]++;
			g[i]/=10;
		}
	}
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i],&c[i]);
	for(int i=1;i<=m;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++)
		{
			if(c[i]<a[j])
			{
				int y=1;
				for(int v=1;v<=b[i];v++)y*=10;
				if(a[j]%y==c[i])
				f[j]=a[j];
			}
			if(c[i]==a[j])
			{
				printf("%d\n",a[j]);
				break;
			}
			if(j==n)
			{
				sort(f+1,f+n+1,cmp);
				for(int v=1;v<=1000;v++)
				{
					if(f[v+1]==0&&f[v]!=0)
					{
						printf("%d\n",f[v]);
						break;
					}
					else if(f[v]==0)
					{
						printf("-1\n");
						break;
					}
				}
			}
		}
	}
	return 0;
}
