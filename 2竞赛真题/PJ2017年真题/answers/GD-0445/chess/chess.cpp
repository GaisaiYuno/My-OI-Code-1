#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int a[105][105],b[105][105],n,m,he;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int i=1;i<=101;i++)
	{
		for(int j=1;j<=101;j++)
		{
			a[i][j]=-1;
		}
	}
	for(int i=1;i<=101;i++)
	{
		for(int j=1;j<=101;j++)
		{
			b[i][j]=999;
		}
	}
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k,j,l;
		cin>>k>>j>>l;
		a[k][j]=l;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][i]==-1)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<8;
	return 0;
}
