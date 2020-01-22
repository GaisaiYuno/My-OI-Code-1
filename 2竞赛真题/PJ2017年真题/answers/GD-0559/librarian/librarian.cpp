#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,i,j,k,x,p,ss,zs,s,ans,l,w,o,a[10000];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) 
	  cin>>a[i];
	sort(a+1,a+n+1);
    for (int i=0;i<q;i++)
    {
    	o=0;
    	cin>>x>>p;
      	for (int j=1;j<=n;j++)
    	{
            w=a[j];
            zs=w%10;
            l=1;s=0;
    		for (int k=1;k<=x;k++)
			{
    		  ans=s*l+zs;
			  w=w/10;
			  s=w%10;
			  l=l*10;
			  zs=ans;
			  if (w==0) break;
    	    }
    		if (zs==p) 
    		{
    			o=1;
    			cout<<a[j]<<endl;
    			break;
    		
			}
    	}
    	if (o==0) cout<<"-1"<<endl;
    }
	return 0;
}
