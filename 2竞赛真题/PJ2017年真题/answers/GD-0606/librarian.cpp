#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,a[1005],b,c[1005],t[1005],min;
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=q;i++) 
	{
		cin>>b>>c[i];
		t[i]=1;
		for (int j=1;j<=b;j++) t[i]=t[i]*10;
	}
	for (int i=1;i<=q;i++)
	{
		min=10000001;
		for (int j=1;j<=n;j++)
			if ((a[j]%t[i]==c[i])&&(a[j]<min)) min=a[j];
		if (min!=10000001) cout<<min<<endl;
			else cout<<-1<<endl;
	}
	return 0;
}
