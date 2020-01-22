#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;
int n,d,kk,a[1000],b[1000],f[1000],mx,x;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>kk;
	for (int i=1;i<=n;i++)
	{
	 scanf("%d%d",&a[i],&b[i]);
	 x=max(x,a[i]);
	}	
	if (n<=500)
	{
	for (int i=0;i<=x;i++)
	{
		for (int j=1;j<=n;j++)
		 f[j]=0;
		mx=0;
		if (i<d)
		{
		 for (int j=1;j<=n;j++)
		 {
		  for (int k=0;k<j;k++)
		  {
		   if (a[j]-a[k]>=d-i&&a[j]-a[k]<=d+i&&f[k]!=0)
		    f[j]=max(f[k]+b[j],f[j]);
		   if (a[j]-a[k]>=d-i&&a[j]-a[k]<=d+i&&j==1)
		    f[j]=b[j];
		   //if (f[j]==0) break;
		 }
		}
		 for (int j=1;j<=n;j++)
		  mx=max(f[j],mx);
	   } 
	   else 
	   {
		 for (int j=1;j<=n;j++)
		 {
		  for (int k=0;k<j;k++)
		  {
		   if (a[j]-a[k]>=1&&a[j]-a[k]<=d+i&&f[k]!=0)
		    f[j]=max(f[k]+b[j],f[j]);
		   if (a[j]-a[k]>=d-i&&a[j]-a[k]<=d+i&&j==1)
		    f[j]=b[j];
		 }
		}
		 for (int j=1;j<=n;j++)
		  mx=max(f[j],mx);
	   } 
	   if (mx>=kk) {cout<<i;return 0;}
	}
    }
	cout<<"-1";
	return 0;
}
