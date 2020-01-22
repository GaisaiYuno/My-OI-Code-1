#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,m,p,s,mi,b,a[100005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		p=0;
		s=1;
		mi=-1;
		cin>>b;
		for(int j=1;j<=b;j++)
		{
			s=s*10;
		}
		cin>>b;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%s==b&&(p==0||a[j]<mi))
			{
				p=1;
				mi=a[j];
			} 
		}
		cout<<mi<<endl;
	}
	return 0;
}
