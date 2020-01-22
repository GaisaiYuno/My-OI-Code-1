#include<iostream>
#include<fstream>
using namespace std;
int n,q,c[1010],f,v;
long long a[1010],b[1010],ans=0,e;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
  cin>>n>>q;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  for(int i=1;i<=q;i++)
  cin>>c[i]>>b[i];
  for(int i=1;i<=q;i++)
  {
  	ans=0;
  	for(int j=1;j<=n;j++)
  	{
  	    long long d=a[j];
  	    f=1;e=0;v=1;
  	    while(f<=c[i])
  	    {
  	    	f++;
  		    e=e+d%10*v;
  		    d=d/10;
  		    v*=10;
  	    }
  	    if(e==b[i]&&j<=n) ans=a[j];
  	    if(e==b[i]&&e<ans) ans=a[j];
      }
      if(ans!=0) cout<<ans<<endl;
      else cout<<"-1"<<endl;
  }
	return 0;
}                             
