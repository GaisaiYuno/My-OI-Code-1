#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[2000],l[2000],f[2000];
int k[9]=
{
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000//  8x'0'
};
int n,q;
bool cmp(int a,int b)
{	return a<b;    }
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(l,0,sizeof(l));
	memset(f,0,sizeof(f));
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>f[i];
	}
	for(int i=1;i<=q;i++)
	{
		bool bo=false;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%k[l[i]]==f[i])
			{
				cout<<a[j]<<endl;
				bo=true;
				break;
			}
		}
		if(!bo)//Not found
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}

