#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,q,t,d,s,w,y,r,a[1000+5],b[20];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=q;i++)
	 {
	    scanf("%d%d",&m,&t);
	    w=0;
	    for (int j=1;j<=n;j++)
	     {
	     	y=a[j];s=0;
	     	if (y==t)
			 {cout<<t<<endl;w=1;break;}
			if (y>t)
	     	{
	     	  for (int k=1;k<=r;k++)
	     	    b[k]=0;
	     	  r=m;
	     	  for (int k=1;k<=m;k++)
	     	   {
	     	 	d=y%10;
	     	 	y=y/10;
	     	 	b[r]=d;
	     	 	r--;
	     	   }
	     	  for (int j=1;j<=m;j++)
	     	    s=s*10+b[j];
	     	  if (s==t)
			   {cout<<a[j]<<endl;w=1;break;}
	     	}
	     }
	     if (w==0) cout<<-1<<endl;
     }
	return 0;
}
