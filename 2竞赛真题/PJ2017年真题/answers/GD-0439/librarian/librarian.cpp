#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1001],x,T,t;
bool bz;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d%d",&t,&x);
		for (int j=1;j<=n;j++)
		{
			T=x,t=a[j];
			bz=1;
			while (T)
			{
				if (t==0) 
				{
					bz=0;
					break;
				}
				if (T%10!=t%10) 
				{
					bz=0;
					break;
				}
				T=T/10;
				t=t/10;
			}
			if (bz) 
			{
				printf("%d\n",a[j]);
				break;
			}
		}
		if (!bz) printf("-1\n");
	}
}
