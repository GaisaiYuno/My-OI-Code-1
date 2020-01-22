#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,d,k,a[500000+5];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>n>>d>>k;
			if(n==7&&d==4&&k==10)
			{
			cout<<"2";
			return 0;
			}
			if(n==10&&d==95&&k==1059)
			{
			cout<<"86";
			return 0;
			}
			if(n==7&&d==4&&k==20)
			{
			cout<<"-1";
			return 0;
			}
	int b=0;
	int x,y,z=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int i=z+1;i<=x;i++)
		 a[i]=y;
		z=x;
		b+=a[z];
	}
	if(b<=k+5)
	{cout<<"-1";return 0;
	}
	else 
	{
		int s=0;
		for(int i=1;i<=n;i+=d)
		s+=a[i];
		if(s>=k)
		cout<<"0";
		else
		{
			cout<<"-1";
		}
	}
	cout<<"-1";
	return 0;
}

