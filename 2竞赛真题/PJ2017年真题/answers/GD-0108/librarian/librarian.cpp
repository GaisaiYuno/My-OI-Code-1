#include<iostream>
#include<fstream>
using namespace std;
int n,q,a[1010],m,minn,l,x;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n;i++)
	  cin>>a[i];
	for (int i=0;i<q;i++)
	{
		m=1;
		cin>>l>>x;
		for (int j=1;j<=l;j++)
		  m*=10;
		minn=100000000;
		for (int j=0;j<n;j++)
		{
			if (a[j]%m==x&&a[j]<minn) minn=a[j];
		}
		if (minn==100000000) cout<<-1<<endl;else cout<<minn<<endl;
	}
	return 0;
}
