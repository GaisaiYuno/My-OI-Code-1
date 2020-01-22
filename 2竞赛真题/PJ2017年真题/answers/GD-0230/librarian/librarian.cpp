#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,q,z[1005],x[1005],c[1005],a[10];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	  scanf("%d",&z[i]);
	for (int i=1;i<=q;i++)
	{
		scanf ("%d%d",&x[i],&c[i]);
	}
	sort(z+1,z+n+1);
	a[0]=1;
	for (int i=1;i<=7;i++) a[i]=a[i-1]*10;
	for (int i=1;i<=q;i++)
	{
		int l=0;
		for (int j=1;j<=n;j++)
		  if (z[j]%a[x[i]]==c[i]) 
		  {
		  	  printf("%d\n",z[j]);
		  	  l=1;
			  break; 
		  }
		  if (l==0) printf("-1\n");
	}
	return 0;
}
