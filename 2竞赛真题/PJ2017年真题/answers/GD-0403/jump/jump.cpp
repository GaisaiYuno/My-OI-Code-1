#include <iostream>
#include  <cstdio>
using namespace std;
int n,d,k,i,j,l[502],s[502],su=0,mi,ma,k1=-1554656,p,q,o,y,u;
bool e1,e2;
int main()
{
	freopen ("jump.in","r",stdin);
	freopen ("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=1;i<=n;i++)
	{
		cin>>l[i]>>s[i];
		if (s[i]>0)
		{
			su=su+s[i];
		}
		if (l[i]>k1)
		{
			k1=l[i];
		}
	}
	if (su<k)
	{
		cout<<-1;
		return 0;
	}
	
	for (i=1;;i++)
	{
		j=1;p=1;q=1;k1=0;su=0;u=0;
		while (j<=k)
		{
		  e1=false;e2=false;
		  if (i<d)		{
		  			mi=d-i;
		  			ma=d+i;	
					  	}
		  if (i>d)		{	
		  		mi=1;		
				ma=d+i;	
					  	}
		  for (int ll=1;ll<=k;ll++)
		  {
		  	if (l[ll]>=mi+u&&e1==false)
		  	{
		  		p=ll;
		  		e1=true;
		  	}
		  	if (l[ll+1]>ma+u&&e2==false)
		  	{
		  		q=ll;
		  		e2=true;
		  	}
		  }
		  for (o=p;o<=q;o++)
		  {
		  	if (k1<s[o])
		  	{
		  		k1=s[o];
		  		y=o;
		  	}
		  }
		  if (p==q) su+=s[p];
		  else su+=k1;
		  k1=0;
		  if (k<=su)
		  {
		  	cout<<i;
		  	return 0;
		  }
		  if (ma<l[p+1])
		  {
		  	break;
		  } 
		  j=y;
		  p=j;
		  u=l[j];
		}
	}
	return 0;
}
