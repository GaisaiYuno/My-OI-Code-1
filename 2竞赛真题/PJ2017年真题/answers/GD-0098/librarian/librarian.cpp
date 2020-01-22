#include <iostream>
#include <cstdio>
using namespace std;
const int oo=2147483647;
int n,m,a[1000005],num,v;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&num,&v);
			int Mod=1,Min=oo;
			for (int j=1;j<=num;j++)	Mod*=10;
			for (int j=1;j<=n;j++)
					if (a[j]%Mod==v&&a[j]<Min)
						Min=a[j];
			if (Min==oo) printf("-1\n");
			else printf("%d\n",Min);
		}
	return 0;
}
