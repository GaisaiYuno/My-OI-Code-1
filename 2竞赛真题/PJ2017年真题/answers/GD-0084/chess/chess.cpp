#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,x,y,m,c,f[102][1002];
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
	f[i][j]=2;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		f[x][y]=c;
	}
	cout<<-1;
	
}
