#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,q,a[1005],b[1005],c[1005],v=0,r=0,g=1;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=q;i++)
	  cin>>b[i]>>c[i];
	sort(a+1,a+n+1);
    for(int i=1;i<=q;i++)
	{
	    int xx=0;	
	    for(int j=1;j<=n;j++)
	    {
			v=0;
			r=a[j];
			g=1;
	    	for(int k=1;k<=b[i];k++)
	    	{
	    		v=r%10*g+v;
	    		r=r/10;
	    		g=g*10;
	    	}
	    	if(v==c[i])
	    	{
	    		cout<<a[j]<<endl;
	    		xx=1;
	    		break;
	    	}
	    }
	    if(xx==0)
		  cout<<-1<<endl;
	}
	return 0;
}
