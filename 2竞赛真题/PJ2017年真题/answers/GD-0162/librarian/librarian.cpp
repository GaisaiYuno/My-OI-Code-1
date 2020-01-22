#include<iostream>
#include<cstdio>
using namespace std;
int n,p,i,j,cd,xqm,jm,sm,cs,a[2017];
int main()
{
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	cin>>n>>p;
	for (i=1;i<=n;i++)
		cin>>a[i];
	for (i=1;i<=p;i++)
	{
		cin>>cd>>xqm;
		sm=20171111;
		cs=1;
		for (j=1;j<=cd;j++)
		    cs*=10;
		for (j=1;j<=n;j++)
		{
			jm=a[j]%cs;
			if (jm==xqm) 
			   if (sm>a[j]) sm=a[j];			  
		}
		if (sm<20171111) cout<<sm<<endl;	
		if (sm==20171111) cout<<-1<<endl;
	}
	return 0;
}
