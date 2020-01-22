#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	bool z=false;
	long long a[10000],c[10000],t,k;
	int n,q,b[10000],i,j,s=0;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	  cin>>a[i];
	for(i=1;i<=q;i++)
	  cin>>b[i]>>c[i];
	for(i=n;i>=1;i--)
	  for(j=1;j<i;j++)
	    if(a[j]>a[j+1])
	      {
	      	t=a[j];
	      	a[j]=a[j+1];
	      	a[j+1]=t;
	      }
	for(i=1;i<=q;i++)
	  {
	  	z=false;
	  	s=0;
	  	for(j=1;j<=n;j++)
	  	  {
	  	    t=a[j]-c[i];
	        k=t;
	        if(k==0)
	          {
	          	cout<<a[j]<<endl;
	          	z=true;
	          	break;
	          }
	        if(k<0)
	          continue;
	  	    while(k>1)
	  	      {
	  	        if(k%10==0)
	  	          s++;
	  	        k/=10;
	  	      }
	  	    if(s==b[i])
	  	      {
	  	      	cout<<a[j]<<endl;
	  	      	z=true;
	  	      	break;
	  	      }
	      }
	    if(z==false)
	      cout<<"-1"<<endl;
	  }
	return 0;
}
