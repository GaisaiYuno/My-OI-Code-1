#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[1001],x,y;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		long long s=1;
		while (x--) s*=10;
		bool b=true;
		for (int j=1;j<=n;j++)
		{
			if (a[j]%s==y)
			{
				printf("%d\n",a[j]);
				b=false;
				break;
			} 
		}
		if (b) printf("-1\n");
	}
	return 0;
}
