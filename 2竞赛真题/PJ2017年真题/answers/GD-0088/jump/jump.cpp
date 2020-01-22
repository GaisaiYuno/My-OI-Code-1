#include<cstdio>
#include<iostream>
using namespace std;
int n,d,i,s,t,kk,j,k,a[100001],b[100001],f[100001],ans=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&kk);
	for (i=1;i<=n;i++) 
	{
	scanf("%d%d",&a[i],&b[i]);
	if (a[i]%d==0) ans+=b[i];
	}
	s=t=d;
	if (ans>=kk) {printf("0");return 0;}
	for (i=1;i<d;i++)
	{
		s=s-i;t=t+i;
		memset(f,0,sizeof(f));
		for (j=1;j<=n;j++)
		  for (k=s;k<=t;k++)
		    if (a[j]-k==a[j-1])f[a[j]]=max(f[a[j]],f[a[j]-k]+b[j]);
		for (j=1;j<=n;j++)
		  if (f[a[j]]>=kk){printf("%d",i);return 0;}
	}
	for (i=d;i<=a[n]-d;i++)
	{
		s=1;t=t+i;
		memset(f,0,sizeof(f));
		for (j=1;j<=n;j++)
		  for (k=s;k<=t;k++)
		    if (a[j]-k==a[j-1])f[a[j]]=max(f[a[j]],f[a[j]-k]+b[j]);
		for (j=1;j<=n;j++)
		  if (f[a[j]]>=kk){printf("%d",i);return 0;}
	}
	printf("-1");
	return 0;
}
