#include<cstdio>
#include<cmath>
#define oo 2147483647
int n,q,book[10000005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&book[i]);
	}
	for (;q>=1;q--)
	{
		int l,bo;
		scanf("%d%d",&l,&bo);
		l=0;
		int t=bo;
		while (t>0)
		{
			l++;
			t/=10;
		}
		int Mod=pow(10,l),Min=oo;
		for (int i=1;i<=n;i++)
			if (book[i]%Mod==bo)
			{
				if (book[i]<Min) Min=book[i];
			}
		if (Min!=oo) printf("%d\n",Min);
		else
		printf("-1\n");
	}
	return 0;
}
