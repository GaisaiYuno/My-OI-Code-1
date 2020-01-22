#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,i,t,z,x[500005],s[500005],l,r,mid,a,b,t1,t2;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);	
	cin>>n>>d>>k;
	for (i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		if (s[i]>=0) {t+=s[i];}
		z=max(x[i],z);
	}
	if (t<k) {cout<<-1;return 0;}
	z=z-d;
	if (z<=0) {cout<<0;return 0;}
	l=0;r=z+1;
	while (l+1<r)
	{
	  mid=(l+r)/2;a=1;b=0;t1=0;
	  if (mid<d) a=d-mid;
	  while (t1<=k && b!=x[n])
	  {
	  	t=-100001;
	  	for (i=1;i<=n;i++)	
	  	{
	 	  if (x[i]>=b+a && x[i]<=b+mid+d && s[i]>t) {z=x[i];t=s[i];}
	 	  if (x[i]>b+mid+d) break;
	  	}
	  	b=z;t1=t1+t;
	  }
	  if (t1>=k) r=mid;
	   else l=mid;
	}
	cout<<r;
	return 0;
}
