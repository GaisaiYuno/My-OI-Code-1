#include<iostream>
#include<fstream>
using namespace std;
int n,d,g,k,zs,maxx,p,a[100005],b[100005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>g;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if (b[i]>0) zs+=b[i];
	}
	if (zs<g) 
	{
		cout<<"-1";
		return 0;
	}
	for (int i=d;;i++)
	{
		zs=0;
		for (int j=0;j<=n;j=p)
		{
			maxx=-1000000;
			p=0;
			for (int k=j+1;k<=n;k++)
			{
				if (a[j]+i>a[k])
				{
					if (b[k]>maxx)
					{
						maxx=b[k];
						p=k;
					} 
				}
				else break;
			}
			if (maxx!=-1000000) zs+=maxx;
			else if (maxx==-1000000) break;
		}
		if (zs>=g) 
		{
			cout<<i-d;
			break;
		}
	}
	return 0;
}
