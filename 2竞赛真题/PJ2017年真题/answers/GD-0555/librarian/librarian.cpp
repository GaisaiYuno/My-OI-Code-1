#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a[1005],x,b,sum,k,c,d=1000005,t;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		cin>>b>>t;
		sum=0;
		d=10000005;
		for(int j=1;j<=n;j++)
		{
			k=0;
			c=a[j];
			x=t;
		  while(x!=0)
		  { 
		    if(x%10!=c%10)
		  	  k++;
		  	x=x/10;
		  	c=c/10;
		  }
		  if(k==0)
		  {
		  	sum++;
		  	d=min(d,a[j]);
		  }
		   
		}
		if(sum==0)
		  cout<<-1<<endl;
		else
		  cout<<d<<endl;
	}
	return 0;
}
