#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
long long p,n,q,w,a[101],t[1001][11],bm[1001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for (int i=1;i<=n;i++) 
	{
	    scanf("%lld",&bm[i]);
	    int F=bm[i];
	    while (F!=0)
	    {
	    	t[i][F%10]++;
	    	F/=10;
	    }
    }
    for (int i=1;i<=q;i++)
	{
	    scanf("%lld%lld",&p,&w);
	    long long x=w,sum=1,k=0,maxn=10000000,a[101];
	    while (x!=0)
	    {
	    	sum*=10;
			++k;
			a[k]=x%10;
	    	x/=10;
	    }
	    if (k==p)
		{for (int j=1;j<=n;j++)
		  if (bm[j]%sum==w) maxn=min(bm[j],maxn);}
		 else 
		{
			for (int j=1;j<=n;j++)
			{
				bool f=true;
				for (int v=1;v<=k;v++)
				 if (t[a[v]]==0) 
				 {f=false;break;}
				if (f) maxn=min(maxn,bm[j]);
			}
		}
		if (maxn!=10000000) printf("%lld\n",maxn);
		  else printf("-1\n");
    }
    return 0; 
}
