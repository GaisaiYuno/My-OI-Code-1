#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[1001],b,len,z,p;
int hh(int);
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{
		cin>>len>>b;
		z=0;
		for(int k=1;k<=n;k++)
		{
			p=0;
			for(int j=len;j>=1;j--)
			if(b%hh(len-j+1)==a[k]%hh(len-j+1)) p++;
			if(p==len) 
			{
				cout<<a[k]<<endl;
				z=1;
				break;
			}
		}
		if(z==0) cout<<-1<<endl;
	}
	return 0;
}
int hh(int l)
{
	int u=1;
	for(int o=1;o<=l;o++)
	u=u*10;
	return u;
}
