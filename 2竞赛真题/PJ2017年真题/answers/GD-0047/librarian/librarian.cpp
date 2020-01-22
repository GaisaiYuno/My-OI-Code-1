#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
long long n,q,a[1008],b[1008],c[1008],ten[100];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	ten[0]=1;
	for (int i=1;i<=8;i++)
		ten[i]=ten[i-1]*10;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=q;i++)
		cin>>b[i]>>c[i];
	for (int i=1;i<=q;i++)
	{
		long long MIN=10000008;bool t=false;
		for (int j=1;j<=n;j++)
			if (a[j]%ten[b[i]]==c[i]) 
			{
				MIN=min(MIN,a[j]);
				t=true;
			}
		if (t)	cout<<MIN; else cout<<-1;
		cout<<endl;
	}
	return 0;
}
