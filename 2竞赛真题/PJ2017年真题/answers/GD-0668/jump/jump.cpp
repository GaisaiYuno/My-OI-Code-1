#include<iostream>
#include<cstdio>
using namespace std;
long long qw,n,d,b[500005],a[20000005],big,ans,x,y,z[20000005],q,i,j,k;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>qw;
	for (i=1;i<=n;i++) 
	  {
	    scanf("%lld",&b[i]);
		cin>>a[b[i]];
	    if (a[b[i]]>0) big+=a[b[i]];
      }
	for (i=1;i<=b[n]/d;i++) ans+=a[i*d];
	if (ans>=qw)
	  {
	  	cout<<0;
	  	return 0;
	  }
	if (qw>big) 
	  {
	  	cout<<-1;
	  	return 0;
	  }
	for (i=1;i<=b[n];i++)
	  {
	  	ans=0;
	  	memset(z,0,sizeof(z));
	  	for (j=1;j<=b[n];j++)
	  	  {
	  	  	q=0;
	  	  	for (k=d-i+1;k<=d+i-1;k++)
	  	  	  if (j-k>=0&&a[j-k]!=0) q=max(q,z[j-k]+a[j]);
	  	  	z[j]=q;
	  	  	ans=max(z[j],ans);
	  	  }
	  	if (ans>=qw)
	  	  {
	  	  	cout<<i;
	  	  	return 0;
	  	  }
	  }
	cout<<-1;
	return 0;
}
