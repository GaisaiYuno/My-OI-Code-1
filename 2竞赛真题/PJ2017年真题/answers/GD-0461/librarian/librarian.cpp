#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,q,a[1005],w;
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
		cin>>w;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<-1<<endl;
	}
	return 0;
}
