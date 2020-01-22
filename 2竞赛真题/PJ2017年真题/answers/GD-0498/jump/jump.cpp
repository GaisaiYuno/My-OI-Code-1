#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,a[10000],b[10000],c[100000],q,z,x,Max;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		Max=max(Max,a[i]);
	}
	q=0;
	for (int i=1;i<=Max;i++)
	{
		z=m-i;x=m+i;
		if (z<1&&x>Max)break;
		for (int j=1;j<=n;j++)
		{
			c[j]=-500000;
			for (int l=0;l<=n;l++)
			{
				if (a[j]-m+i<a[l]||a[j]<=a[l])break;
				if (a[j]-m-i<=a[l]&&a[j]-m+i>=a[l])
				  {
				  	c[j]=max(c[l]+b[j],c[j]);
				  }
			}
			if (c[j]>=k){q=1;break;}
		}
		if (q==1){printf("%d\n",i);break;}
	}
	if (q==0)printf("-1\n");
	return 0;
}
