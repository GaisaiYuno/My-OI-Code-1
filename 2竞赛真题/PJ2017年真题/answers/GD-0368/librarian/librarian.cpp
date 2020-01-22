#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,q,w,z,x,a[1005],e;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for (int j=1;j<=q;j++)
	{
		cin>>z>>x;
		w=1;e=0;
		for (int k=1;k<=z;k++)
		w*=10;
		for (int i=1;i<=n;i++)
		if (a[i]%w==x) {cout<<a[i]<<endl;e=1;break;}
		if (e==0) cout<<"-1"<<endl;
	}
	return 0;
}
