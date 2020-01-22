#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,q,a[10000],b,c,i,j;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&b,&c);
		int k=1;
		for(j=1;j<=b;j++)k*=10;
		int zt=0;
		for(j=1;j<=n;j++)
		{
			int bj=a[j]%k;
			if(bj==c)
			{
				printf("%d\n",a[j]);
				zt=1;
				break;
			}
		}
		if(zt==0)printf("-1\n");
	}
	return 0;	
}
