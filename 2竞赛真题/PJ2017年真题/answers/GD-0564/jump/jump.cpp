#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,d,k,g,f[500500],temp,l,r,mid;
struct block
{long k,s;};
block b[500500];
int test(int m)
{
  long long left,right,sum=0;
  left=d-m;right=d+m;
  if (left<1)left=1;
  for (int i=1;i<=n;i++)
   f[i]=-50000000000;
  for (int i=1;i<=n;i++)
   {
   	 temp=i;
   	 while(b[temp].k>b[i].k-left)temp--;
   	 while(b[temp].k>=b[i].k-right&&temp>=0)
   	  {
   	   if (f[temp]+b[i].s>f[i])
   	    f[i]=f[temp]+b[i].s;
	   temp--;
	  }
   }
  for (int i=0;i<=n;i++)
   sum=max(sum,f[i]);
  return sum>=k; 
}
int main()
{
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);
  cin>>n>>d>>k;
  for (int i=1;i<=n;i++)
   {scanf("%d%d",&b[i].k,&b[i].s);
    temp+=b[i].s>0?b[i].s:0;}
  if (temp<k)
   {cout<<"-1";
    return 0;}
  l=0;r=2000000000;
  while(l<r)
   {
   	 mid=(l+r)>>1;
   	 if (test(mid))r=mid;
   	 else l=mid+1;
   }
  cout<<l;
  return 0;
}
