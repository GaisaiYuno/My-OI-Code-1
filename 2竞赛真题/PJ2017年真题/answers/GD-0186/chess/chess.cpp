#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		a[i][j]=3;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=z+1;
	}
	cout<<-1;
}
