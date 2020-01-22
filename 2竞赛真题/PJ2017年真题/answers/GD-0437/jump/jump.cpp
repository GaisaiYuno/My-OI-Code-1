#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,d,t,s,b[500000+5],c[500000+5];
long long a[500000+5],p,ma;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>p;
	for (int i=1;i<=n;i++)
	  {
	     scanf("%lld",&a[i]);
		 scanf("%d",&b[i]);
	     if (b[i]>0) s+=b[i];
	     ma=max(ma,a[i]);
      }
    if (s<p) {cout<<-1;return 0;}
    for (int i=0;i<=ma;i++)
      for (int j=1;j<=n;j++)
       {
		 m=0;t=0;c[j]=0;
		 for (int k=1;k<j;k++)
		   if (a[k]-a[k-1]>=d-i&&a[k]-a[k-1]<=d+i)
		     {m=max(m,b[k]);c[k]=1;}
		 
		 if (a[j]-a[j-1]>=d-i&&a[j]-a[j-1]<=d+i&&c[j-1]==1)
		   m+=b[j];
		 if (m>=p) {cout<<i;return 0;}
       }
    cout<<-1;
	return 0;
}
