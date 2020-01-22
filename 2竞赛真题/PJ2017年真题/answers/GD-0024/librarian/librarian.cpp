#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
int q,p,n,w,o,c,y,k,u;
int main()
{
    freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>q;
    
    for (int i=1;i<=n;i++)
     scanf("%d",&a[i]);
     
     sort(a+1,a+n+1);
	  
	 for (int i=1;i<=q;i++)
	  {
	  	c=0;
	  	scanf("%d%d",&u,&p);
	  	for (int o=1;o<=n;o++)
	  	{
         y=a[o];w=p;k=0;
	  	 
		 for (int j=1;j<=u;j++)
	  	  if ((y%10 != w%10 ) || y==0 ) {k=1;break;}
	  	  else {y/=10;w/=10;}
	  	 
		 if (k==0) {c++;printf("%d\n",a[o]);break;}   
        }
        if (c==0) printf("%d\n",-1);
	  } 
	return 0;
}
