#include <cstdio>
#include <iostream>
#include <cstring>
#define oo 10000005LL

using namespace std;

int n,m,a[1005],PowTen[10];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	PowTen[1]=10;
	for (int i=2;i<=8;i++)
		PowTen[i]=PowTen[i-1]*10;
	for (int i=1,len,num;i<=m;i++)
	{
		scanf("%d%d",&len,&num);
		int ans=oo;
		for (int j=1;j<=n;j++)
		{
			int x=a[j]%PowTen[len];
			if (x==num&&a[j]<ans)
				ans=a[j];
		}
		if (ans==oo) printf("-1\n");
			else printf("%d\n",ans);
	}
	return 0;
}
