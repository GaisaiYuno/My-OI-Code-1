#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
long long w[501000],v[501000];
long long f[501000];
long long n,d,k;
long long check (long long mi,long long ma)
{
	memset (f,0,sizeof (f));
	long long ans=0;
	int cur=0;
	if (w[1]<mi||w[1]>ma) return 0;
	f[1]=v[1];
	for (int i=2; i<=n; i++)
	{
		for (int j=i-1; j>=0; j--)
		{
			if (w[i]-w[j]<mi) continue;
			if (w[i]-w[j]>ma) break;
			f[i]=max (f[i],f[j]+v[i]);
		}
		ans=max (ans,f[i]);
	}
	return ans;
}
int main()
{
	freopen ("jump.in","r",stdin);
	freopen ("jump.out","w",stdout);
	memset (w,0,sizeof (w));
	memset (v,0,sizeof (v));
	cin>>n>>d>>k;
	long long sum=0;
	for (int i=1; i<=n; i++)
	cin>>w[i]>>v[i],sum+=(bool)(v[i]>0)*v[i];
	if (sum<k)
	{
		cout<<-1;
		return 0;
	}
	if (check (d,d)>=k)
	{
		cout<<0;
		return 0;
	}
	long long l=0,r=w[n]+10;
	while (l+1!=r)
	{
		long long mid=(l+r)/2;
		long long a,b=d+mid;
		if (d-mid<1) a=1;
		else a=d-mid;
		if (check (a,b)>=k) r=mid;
		else l=mid;
	}
	cout<<r;
	return 0;
}

