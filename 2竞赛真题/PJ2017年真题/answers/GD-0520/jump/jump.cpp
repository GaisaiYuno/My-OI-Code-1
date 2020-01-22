#include<iostream>
#include<cstdio>
using namespace std;
int jl[1000001],gs,n,d,k,i,p[1000001],s[1000001],l,r,mid,f[1000001];
int check1(int gpbt)
{
	for (int i=1; i<=n; i++)
	{
	 	for (int j=0; j<=i-1; j++)
	 	 if (p[i]-p[j]>=d-gpbt&&p[i]-p[j]<=d+gpbt&&jl[j]==1)
	 	{
	 		if (f[i]==-1) f[i]=f[j]+s[i]; else f[i]=max(f[i],f[j]+s[i]);
	 		jl[i]=1;
	    }
		if (f[i]>=k) return 1;
	}
	return 0;
}
int check2(int gpbt)
{
	for (int i=1; i<=n; i++)
	{
	 	for (int j=0; j<=i-1; j++)
	 	 if (p[i]-p[j]>=1&&p[i]-p[j]<=d+gpbt&&jl[j]==1)
	 	{
		 	if (f[i]==-1) f[i]=f[j]+s[i]; else f[i]=max(f[i],f[j]+s[i]);
		 	jl[i]=1;
		}
	 	if (f[i]>=k) return 1;
	}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	for (i=1; i<=n; i++)
	{
	  	jl[i]=0;
	  	f[i]=-1;
	}
	jl[0]=1;
	cin>>n>>d>>k;
	for (i=1; i<=n; i++)
	 cin>>p[i]>>s[i];
	l=-1;
	r=1000000000;
	while (l+1<r)
	  {
	  	for (i=1; i<=n; i++)
	  	 {
	  	 	jl[i]=0;
	  	 	f[i]=-1;
	  	 }
	  	mid=(l+r)/2;
	  	if (mid<d) gs=check1(mid); else
	  	gs=check2(mid);
		if (gs==1) r=mid; else
	  	l=mid;
	  }
	if (r<d) gs=check1(r); else
	gs=check2(r);
	if (gs==0) cout<<-1; else cout<<r;
	return 0;
}
