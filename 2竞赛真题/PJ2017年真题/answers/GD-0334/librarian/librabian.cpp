#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a[10005],b[10005],d[10005],c=10;
long long h[10005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		cin>>b[i];
		scanf("%lld",&h[i]);
	}
	for(int i=1;i<=q;i++)
	{
		d[i]=100000000;
		for(int j=2;j<=b[i];j++)
		c*=10;
		for(int k=1;k<=n;k++)
		{
			if(a[k]*10/c>0)
			{
				if(a[k]%c==h[i]||a[k]==h[i])
				d[i]=min(d[i],a[k]);
			}
		}
		if(d[i]==100000000) d[i]=-1;
		c=10;
	}
	for(int i=1;i<=q;i++)
	cout<<d[i]<<endl;
	return 0;
}
