# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <string>
using namespace std;
long long  n,m,a,b,c,len,gs[100000+5];
string st[10000+5],st1,st2;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
		 { 
		   cin>>st[i];
		   gs[i]=0;
		   for (int j=0; j<st[i].length(); j++)
		    {
		      gs[i]=(st[i][j]-48)+gs[i]*10;
		    }
	     }
    for (int i=1; i<=m; i++)
    {
    	cin>>a>>st1;
    	b=-1;
    	c=0;
    	long long ma=4000000000LL;
    	for (int j=1; j<=n; j++)
    	  {
    	  	len=st[j].length();
    	  	if (len-st1.length()>=0)
    	  	{
    	  	st2=st[j].substr(len-st1.length(),st1.length());
    	  	if (st2==st1) 
			   { ma=min(gs[j],ma);c=1;}
		    }
    	  }
    	if (c==0) {cout<<-1<<endl; }
    	else cout<<ma<<endl;
    }
	return 0; 
}
