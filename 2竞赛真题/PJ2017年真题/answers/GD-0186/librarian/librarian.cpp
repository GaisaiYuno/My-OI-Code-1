#include<iostream>
#include<fstream>
using namespace std;
int n,q,a[1001],min1,o,k,b,c;
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
		o=1;
		min1=10000001;
		k=0;
		cin>>b>>c;
		for(int i=1;i<=b;i++)
		o*=10;
		for(int j=1;j<=n;j++)
		{
			
			if(a[j]%o==c)
			{
				if(a[j]<min1)
				min1=a[j];
				k=1;
			}
		}
		if(k==1)
		cout<<min1<<endl;
		else
		cout<<-1<<endl;
	}
}
