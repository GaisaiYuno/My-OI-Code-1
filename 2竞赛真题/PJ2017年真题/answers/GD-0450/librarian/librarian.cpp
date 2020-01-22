#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[1000+5],m,mi,b,x,o;
char g;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	{
		mi=100000000;
		cin>>m>>b;
		x=1;o=1;
		for(int i=1;i<=m;i++) x*=10;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%x==b) 
			{
				o=0;
				mi=min(mi,a[j]);
			}
		}
		if(o==1) cout<<-1<<endl;
		else cout<<mi<<endl;
	}
	return 0;
}
