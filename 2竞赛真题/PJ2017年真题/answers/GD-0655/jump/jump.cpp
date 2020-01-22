#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int d,n,x[500005],b[500005],a[500005];
long long f[500005],ma,k;
bool check(int m)
{
   for (int i=2;i<=n;i++)
   {
   	 for (int j=i-1;j>=1;j--)
   	    if (x[i]-m<=x[j]&&x[i]+m-d>=x[j])f[i]=max(f[i],f[j]+a[i]);
   }
   int maa=0;
   for (int i=1;i<=n;i++)if (f[i]>maa)maa=f[i];
   if (maa>=k)return true;
   return false;
}
int main()
{
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);	
  cin>>n>>d>>k;long long sum=0;
  for (int i=1;i<=n;i++)
  {scanf("%d%d",&x[i],&a[i]);if (x[i]>ma)ma=x[i];if (a[i]>0)sum+=a[i];}
  if (sum<k){cout<<-1;exit(0);}
  int l=d;f[x[1]]=a[1];
  while (l<ma)
  {
  	if (check(l)){cout<<l-d;exit(0);}
  	l++;
  }
  cout<<ma;
  return 0;	
}
