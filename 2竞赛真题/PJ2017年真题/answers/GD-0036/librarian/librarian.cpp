#include<iostream>
#include<stdio.h>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1111],b[1111],c[1111];
int n,q,u,s1;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=q;++i) cin>>b[i]>>c[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=q;++i)
	{
		u=0;
		s1=pow(10,b[i]);
		for (int j=1;j<=n;++j)
		{
			if (a[j]%s1==c[i]) 
			{
				++u;
				cout<<a[j]<<endl;
				break;
			}
		}
		if (u==0) cout<<"-1"<<endl;
	}
	return 0;
}
