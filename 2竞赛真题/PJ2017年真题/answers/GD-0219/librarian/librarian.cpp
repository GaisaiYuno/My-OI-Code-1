#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,q,a[1005],b,c,x[10]={1,10,100,1000,10000,1000000,10000000,100000000,1000000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		int minl=100000007;
		cin>>b>>c;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%x[b]==c)
			minl=min(minl,a[j]);
		}
		if(minl==100000007)
		cout<<-1<<endl;
		else
		cout<<minl<<endl;
	}
	return 0;
}
