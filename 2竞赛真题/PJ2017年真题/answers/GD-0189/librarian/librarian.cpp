#include<iostream>
#include<cstdio>
using namespace std;

int n,q,book[1001],length[1001],need[1001],ans=-1,oops[1001];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>book[i];
		//oops[i]=book[i];
	}
	for(int i=1; i<=q; i++)
	  cin>>length[i]>>need[i];
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=q; j++)
	  {
	     oops[j]=book[j]%10;
	  	  for(int z=j-1; z>=1; z--)
	  	    if(oops[j]==oops[z] && book[j]<book[j-1])
	  	      ans=book[j];
	  	
	  }
	  cout<<ans<<endl;
	}
	return 0;
}
