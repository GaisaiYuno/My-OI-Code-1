#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
int s[1005],w[1005],l[1005],v[1005],h[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	int n,m,q=1,min=50000000;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&s[i]);
	for (int i=1;i<=m;i++)
	scanf("%d%d",&w[i],&l[i]);
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=w[i];j++)
		q=q*10;
		for (int k=1;k<=n;k++)
		{
			v[k]=s[k]%q;
			if (v[k]==l[i]&&s[k]<=min)
			{
				min=s[k];
			}
		}
		if (min<50000000)printf("%d\n",min);
		else printf("%d\n",-1);
		q=1;min=50000000;		
	}
	
	return 0;
}
