#include<iostream>
#include<cstdio>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1500],b[1500],st=0,n,q,w;
int ans;
bool r;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++)
	    scanf("%d",&a[i]);
	for(int i=1; i<=q; i++)
	{
		scanf("%d%d",&w,&b[i]);
		ans=1000000000;
	    st=pow(10,w);
	    r=false;
	    for(int j=1; j<=n; j++)
	    {
		    int m;
		    m=a[j]%st;

		    if(m==b[i])
		    {
			    r=true;
			    if(a[j]<ans)
			        ans=a[j];
		    }
		    
	    }
	    if(r)
		    cout<<ans<<endl;
		else
	        cout<<"-1"<<endl;
	}
	return 0;
	
}
