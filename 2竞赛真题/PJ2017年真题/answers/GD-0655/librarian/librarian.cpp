#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[10005],b,x,n,q,m;
int main()
{
  freopen("librarian.in","r",stdin);
  freopen("librarian.out","w",stdout);
  cin>>n>>q;
  for (int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
  for (int i=1;i<=q;i++)
  {
  	 cin>>b>>x;m=1;bool f=true;
  	 for (int k=1;k<=b;k++)m*=10;
  	 for (int j=1;j<=n;j++)
  	  if (a[j]>=x&&a[j]%m==x){f=false;cout<<a[j]<<endl;break;}
  	 if (f)cout<<-1<<endl; 
  }
  return 0;	
}
