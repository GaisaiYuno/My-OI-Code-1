#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int d,n,f[500005],a[500005],b[500005];
bool cs[500005];
long long k;
bool check(long long mid)
{
	for(int i=1;i<=n;i++)
	  cs[i]=false;
	long long x=d-mid;
	if(x<0)
	  x=1;
	long long y=d+mid;
	if(x>a[1]||y<a[1])
	  return false;
	for(int i=1;i<=n;i++)
	  f[i]=b[i];
	int o=n;
	cs[1]=true;
	for(int i=1;i<=n;i++)
	{
		if(cs[i]==true)
		{
			for(int j=i+1;j<=n;j++)
		    {
			    if(a[i]+x<=a[j]&&a[i]+y>=a[j])
			    {
			    	cs[j]=true;
				    f[j]=max(f[j],f[j]+f[i]);
			    }
		    }
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ans<f[i]&&cs[i]==true)
		  ans=f[i];
	}
	if(ans>=k)
	  return true;
	else
	  return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		f[i]=b[i];
		if(b[i]>0)
		  sum+=b[i];
	}
	if(sum<k)
	{
		cout<<-1;
		return 0;
	}
	long long l=1,r=1000000000;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(check(mid)==true)
		  r=mid;
		else
		  l=mid+1;
	}
	cout<<l;
	return 0;
}
