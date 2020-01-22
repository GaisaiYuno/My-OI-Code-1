#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int a[1005],b[1005],n,q,x[1005];
int main()
{
   freopen("librarian.in","r",stdin); freopen("librarian.out","w",stdout);
   cin>>n>>q;
   for (int i=1;i<=n;i++)
     cin>>a[i];
   sort(a+1,a+1+n);
   for (int i=1;i<=q;i++)
     cin>>x[i]>>b[i];
   for (int i=1;i<=q;i++)
   {
   	  int p=0;
   	  int k=1;
   	  for (int j=1;j<=x[i];j++) k*=10;
   	  for (int j=1;j<=n;j++)
   	    if ((a[j]-b[i])%k==0) {cout<<a[j]<<endl;p=1;break;}
   	  if (p==0) cout<<-1<<endl; 
   }
   return 0;
}
