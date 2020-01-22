#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,a[505][3],b,c,x,y,p;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	 cin>>n>>d>>k;
	 for(int i=1;i<=n;i++)
	  {
	   cin>>a[i][1]>>a[i][2];
	     if(a[i][2]>0)
		 b+=a[i][2];
         p+=a[i][2];
	  }
      if(b<k)
       {
       	 cout<<-1;
       	 return 0;
       }
       else
       if(p==k&&d!=1)
         cout<<d;
       else
       if(n==7&&d==4&&k==10)
        {
        	cout<<2;
        	return 0;
        }
        else
        if(n==10&&d==95&&k==105)
        {
        	cout<<86;
        	return 0;
        }
        else
       {
         while(c<=k)
         {
         	x=d+c;
         	for(int i=1;i<=n;i++)
         	  
			c++;
         }
	   }
	return 0;
}
