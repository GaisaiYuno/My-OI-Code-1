#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int n,q,a[1005],f[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=1;i<=q;i++)
    {
    	int b,c;
    	cin>>b>>c;
    	int ans=-1;
    	for(int j=1;j<=n;j++)
    	{
    		int x=a[j],y=c;
    		bool l=true;
    		while(y>0)
    		{
    			int x1=x%10,y1=y%10;
    			if(x1!=y1)
    			{
    				l=false;
    				break;
    			}
    			x=x/10;
    			y=y/10;
    		}
    		if(l==true)
    		{
    			if(ans==-1)
    			{
    				ans=a[j];
    			}
    			else
    			{
    				if(ans>a[j])
    				  ans=a[j];
    			}
    		}
    	}
		cout<<ans<<endl;
    }
    return 0;
}
