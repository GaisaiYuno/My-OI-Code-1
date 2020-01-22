#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
   freopen("librarian.in","r",stdin);
   freopen("librarian.out","w",stdout);	
   int n,q,k,len,p;
   bool f;
   string st1[1005],st2,st3="",st4,st5,st6;
   cin>>n>>q;
   for (int i=1;i<=n;i++) cin>>st1[i];	
   for (int i=1;i<=q;i++)
    {
       cin>>k>>st2;
       f=false;
	   for (int j=1;j<=n;j++)
	   {	
	      st4=st1[j];
	      len=st4.length();
	      if (len>=k)
	      {
	        st3=st4.substr(len-k,k);
	        if ((st3==st2)&&(f==false))
	         {
		       p=j;
		       f=true;
		     }   
		    if (f==true)
		      if (st3==st2)
		       {
		         st5=st1[j];
			     st6=st1[p];
			     if (st5.length()<st6.length()) p=j;
			     if ((st5.length()==st6.length())&&(st5<st6)) p=j;
		       }
	       }
	    }
	    if (f==true) cout<<st1[p]<<endl;
	    if (f==false) cout<<"-1";
    }
	return 0;		
}
