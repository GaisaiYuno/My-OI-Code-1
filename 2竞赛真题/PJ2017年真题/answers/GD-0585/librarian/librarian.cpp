#include<iostream>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int a,b,shu[1010],lo,bian,ans, x,y,z,shu1,bian1;
	bool bo;
	cin>>a>>b;
	for(x=1;x<=a;++x)
	    cin>>shu[x];
	for(x=1;x<=b;++x)
	{
		cin>>lo>>bian;
		ans=-1;
		for(y=1;y<=a;++y)
		{
			bo=0;
			for(shu1=shu[y],bian1=bian;bian1>0;shu1/=10,bian1/=10)
			    if(shu1%10!=bian1%10)
			    {
			    	bo=1;
			    	break;
			    }
			if(!bo)
			{
				if(ans==-1||ans>shu[y])
				    ans=shu[y];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
