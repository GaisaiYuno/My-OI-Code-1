#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[2100],b[2100],c[2100];
int pd(int x,int y,int z)
{
	int s=x-y,ss=1;
	for(int k=1;k<=z;k++)ss*=10;
	if(s%ss==0)return 1;
	else return 0;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&c[i],&b[i]);
	for(int i=1;i<=m;i++)
	{
		int minn=999999999,bk=0;
		for(int j=1;j<=n;j++)
		{
			if(pd(a[j],b[i],c[i]))
			{
				if(minn>a[j])
				{
					minn=a[j];bk=1;
				}
			}
		}
		if(bk==0)minn=-1;
		printf("%d\n",minn);
	}
	return 0;
}
