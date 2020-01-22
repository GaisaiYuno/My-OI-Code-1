#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
long a[1001],b,c[1001],d[1001],f[1001],o,kk,k,nn,n,m,e,p,q;
int main()
{
     freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	  for(int i=1;i<=n;i++)
	  {
	    cin>>a[i];
	  }
	    sort(a+1,a+n+1);
	    for(int i=1;i<=n;i++)
	      f[i]=a[i];
	    for(int i=1;i<=m;i++)
	    {
	      	cin>>nn>>b;k=0;q=0;
	      	while(b!=0)
	        {
	           	k++;
	            c[k]=b%10;
	           	b/=10;
	        }
	         for(int j=1;j<=n;j++)
	         {kk=0;e=f[j];p=0;o=0;
	           	 while(e!=0)
	           	 {
	           	 	kk++;
	           	 	d[kk]=e%10;
	           	 	e/=10;
	             }
	        if(nn<=kk)
	         for(int j1=1;j1<=nn;j1++)
	           {
	           	 if(c[j1]==d[j1])
	           	 	o++;
	           	   else
	           	   {o=0;break;}
	               if(o==nn)
				     {
	           	      cout<<f[j]<<endl;
                       p=-1;q=-1;break;
	                 }
	            }
	            if(p==-1)break;
	         }
	         if(q!=-1)
	         {
	         cout<<-1<<endl;q=0;
	         }
	    }
	    return 0;
}
