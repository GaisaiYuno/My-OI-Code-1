#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,i,j,a[100000],b[100000],c[100000],d[100000],y,k,l,h,g,mxx;
int main()
{
	 freopen("librarian.in","r",stdin);
     freopen("librarian.out","w",stdout);
    cin>>n>>m;
	for (i=1;i<=n;i++)
	   {
	   	cin>>a[i];
	   }	
	for (i=1;i<=m;i++)
	   {
	   	cin>>b[i]>>c[i];
	   }
	for (i=1;i<=m;i++)
	   {  
	       
	       mxx=1000000001;
	   	  for (j=1;j<=n;j++)
	   	   {
	   	   	  h=a[j];
	   	   	  y=c[i];
	   	   	  while (h!=0)
	   	   	    {
	   	   	    	k=h%10;
	   	   	    	if (k==y%10&&y!=0)
	   	   	    	  {
	   	   	    	  	 g=g+1;
	   	   	    	  	 y=(y-(y%10))/10;
	   	   	    	  }
	   	   	    	else
					  {	
	   	   	            break;
				      }
	   	   	    	h=(h-k)/10;
	   	   	    }
	   	   	  if (g==b[i])
	   	   	    {
	   	   	    	if (a[j]<mxx) mxx=a[j];
	   	   	    }
	   	   	    g=0;
	   	   }
	   	   if (mxx!=1000000001)d[i]=mxx; else d[i]=-1;
	   }
	  for (i=1;i<=m;i++)
	    {
	    	cout<<d[i]<<endl;
	    }
	return 0;
}
