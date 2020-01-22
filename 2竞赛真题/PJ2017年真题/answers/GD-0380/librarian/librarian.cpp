#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,l,f,bm,cd,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++)
	{
		cin>>cd>>bm;
		l=1,f=0;
		for(int k=1;k<=cd;k++) l=10*l;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%l==bm)
			{
				cout<<a[j]<<endl;
				f=1;
				break;
			}
		}
		if(f==0) cout<<-1<<endl;
	}
	return 0;
}
