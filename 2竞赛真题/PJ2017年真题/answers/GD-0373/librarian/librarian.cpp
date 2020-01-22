#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,k[10],l[10];
long long a[1005];
bool work2(long long b,long long c,int o)
{
	for(int i=1;i<=10;i++)
	{
		k[i]=0;
		l[i]=0;
	}
	int d=1;
	while(b!=0)
	{
		k[d]=b%10;
		b/=10;
		d++;
	}
	int r=1;
	while(c!=0)
	{
		l[r]=c%10;
		c/=10;
		r++;
	}
	for(int i=1;i<=o;i++)
	{
		if(k[i]!=l[i])
		  return false;
	}
	return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++)
	{
		int g,s;
		cin>>g;
		cin>>s;
		bool sf=0;
		for(int j=1;j<=n;j++)
		{
			if(work2(s,a[j],g)==true)
			{
				cout<<a[j]<<endl;
				sf=1;
				break;
			}
		}
		if(sf==0)
		  cout<<"-1"<<endl;
	}
	return 0;
}
