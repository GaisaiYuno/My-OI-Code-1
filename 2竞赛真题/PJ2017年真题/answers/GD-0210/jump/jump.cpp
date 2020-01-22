#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,x,a[100000],b[100000],k,y,s,t,z,r,i,ans,q;
int main()
{
     freopen("jump.in","r",stdin);
     freopen("jump.out","w",stdout);
	cin>>n>>m>>x;
	for (i=1;i<=n;i++)
	  {
	  	cin>>a[i]>>b[i];
	  	if (b[i]>0)q=q+b[i];
	  }
	if (q<x) cout<<-1; else
	
	while (t!=1)
	  {
	  	k=k+1;
	  	if (k<m)
	  	  {
	  	  	y=m-k;
	  	  	s=m+k;
	  	  }
	  	if (k>=m)
	  	  {
	  	  	y=1;
	  	  	s=m+k;
	  	  }
	  	while (z!=n)
	  	  {
	  	  	 z=z+1;
	  	  	 r=r+y;
	  	  	 if (r<=a[z])
	  	  	  {
	  	  	  	r=a[z];
	  	  	  	ans=ans+b[z];
	  	  	  }
	  	  	  if (z==2)
	  	  	   {
	  	  	   	 if ((r+(2*s))<a[z]) break;
 	  	  	   }
	  	  }
	  	if (z==n&&ans>=x)
	  	 {
	  	 	cout<<k;
	  	 	break;
	  	 }
	  	 ans=0;
	  	 z=0;
	  	 r=0;
	  }
	return 0;
}
