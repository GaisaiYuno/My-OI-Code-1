#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int a[500005],b,n,d,x[500005];
long long t,f[500005];
bool fl;
bool check(int k)
{
	long long p=d-k,q=d+k;
	if (p<1) p=1;
	for (int i=1;i<=n;i++) f[i]=-1000000000LL;
	for (int i=1;i<=n;i++)
	{
	  for (int j=i-1;j>=0;j--)
	    if (x[i]-x[j]>=p && x[i]-x[j]<=q ) f[i]=max(f[i],f[j]);
	    else if (x[i]-x[j]>q) break;
	  f[i]+=a[i];
	}
	long long m=-1000000000LL;
	for (int i=1;i<=n;i++)
	  m=max(m,f[i]);
	if (m>=t)
	{
		fl=true;
		return true;
	}
	return false;
}
int main()
{
   freopen("jump.in","r",stdin); freopen("jump.out","w",stdout);
   cin>>n>>d>>t;
   int l=0,r=0,m;
   for (int i=1;i<=n;i++)
   {
  	  scanf("%d%d",&x[i],&a[i]);
   	  r=max(r,x[i]); 
   }
   r+=1;
   fl=false;
   while (l+1<r)
   {
   	  m=(l+r)/2;
   	  if (check(m)) r=m; else l=m;
   }
   if (fl)cout<<r; else cout<<-1;
   return 0;
}
