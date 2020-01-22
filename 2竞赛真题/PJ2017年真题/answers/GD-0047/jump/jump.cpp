#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int n,k,a,s;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>k>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>a;
		if (a>0) s+=a;
	}
	if (s<k) cout<<-1; else cout<<0;
	return 0;
}
