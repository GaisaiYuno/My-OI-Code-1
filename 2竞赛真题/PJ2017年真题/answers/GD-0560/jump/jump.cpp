#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,a[500005],b[500005],s;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if (b[i]>0) s+=b[i];
	}
	if (s<k)
	{
		cout<<-1;
		return 0;
	}
	cout<<2;
	return 0;
}
