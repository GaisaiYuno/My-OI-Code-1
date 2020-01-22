#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n=0,q=0,t=0,i=0,j=0,k=0;
	char a[1100][10],b[1100][10];
	int c[1100]={0},d[1100]={0},e[1100]={0},f[1100]={0};
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&d[i]);
		getchar();
		gets(a[i]);
	}
	for(i=1;i<=n;i++)
	{
		j=0;
		t=c[i];
		while(t!=0)
		{
			b[i][j]=(t%10)+'0';
			f[i]++;
			t/=10;
			j++;
		}
	}
	for(i=1;i<=q;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(d[i]<=f[j])
			{
				t=0;
				for(k=0;k<d[i];k++)
				{
					if(b[j][k]!=a[i][d[i]-1-k])
					{
						t++;
						break;
					}
				}
			}
			if(t==0)
			{
				e[i]=c[j];
				t=1;
				break;
			}
			else
			{
				if(j==n)
				{
					e[i]=-1;
				}
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		printf("%d\n",e[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
