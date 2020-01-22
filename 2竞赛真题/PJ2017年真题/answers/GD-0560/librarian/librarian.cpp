#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[1050],x,z,n,m,t;
bool b;
int bx[8]={1,10,100,1000,10000,100000,1000000,10000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	  cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<m;i++)
	{
		b=1;
		cin>>x>>z;
		for (int j=0;j<n;j++)
		{
			t=a[j]%bx[x];
			if (t==z)
			{
				cout<<a[j]<<endl;
				b=0;
				break;
			}
		}
		if (b) cout<<-1<<endl;
	}
	return 0;
}
