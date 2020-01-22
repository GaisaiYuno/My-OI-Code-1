#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool k,t;
int n,p,l,ln,a[1010],b,c,d;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=p;i++)
	{
		scanf("%d%d",&ln,&b);
		k=true;
		for (int j=1;j<=n;j++)
		{
			c=a[j];
			d=b;
			t=true;
			if (d==0&&c%10==0)
			{
				printf("%d\n",a[j]);
				break;
			}
			while (d>0)
			{
				if (d%10!=c%10)
				{
					t=false;
					break;
				}
				c/=10;
				d/=10;
			}
			if (t)
			{
				printf("%d\n",a[j]);
				k=false;
				break;
			}
		}
		if (k) printf("-1\n");
	}
	return 0;
}
