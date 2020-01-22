#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a[1100],b[1100],c[1100],g[1100],e;
int main()
{
	freopen("librarina.in","r",stdin);
	freopen("librarina.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i]>>c[i];
		g[i]=11000000;
	}	
	for(int i=1;i<=q;i++)
	{
		e=0;
		for(int j=1;j<=n;j++)
		if(a[j]>=c[i])
		{
			int d=a[j],f=1;
			for(int k=1;k<=b[i];k++)
			f*=10;
			d%=f;
			if(d==c[i]&&a[j]<g[i])
			{
				g[i]=a[j];
				e=1;	
			}
		}
		if(e==0)
		g[i]=-1;
	}
	for(int i=1;i<=q;i++)
	cout<<g[i]<<endl;
	return 0;
}
