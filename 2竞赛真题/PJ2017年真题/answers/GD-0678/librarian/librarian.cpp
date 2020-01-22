#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,p,a[1005],b[1005],c[1005],e,f,y,t,tt,k;
int main()
{
  freopen("librarian.in","r",stdin);
  freopen("librarian.out","w",stdout);
  cin>>n>>p;
  for (int i=1;i<=n;i++)
   cin>>a[i];
   for (int i=1;i<=p;i++)
   cin>>b[i]>>c[i];
   sort(a+1,a+1+n);
   for (int i=1;i<=p;i++)
    {k=0;
	for (int j=1;j<=n;j++)
      {
     	 e=a[j];
		 f=c[i];
		 y=0;
     	 while (f!=0)
     	 {
     	   t=e%10;
     	   tt=f%10;
     	   e=e/10;f=f/10;
     	   if (t!=tt){y=1;break;}
         }
         if (y==0){k=1;cout<<a[j]<<endl;break;}
      }
      if (k==0)cout<<-1<<endl;
  }
   return 0;
}
