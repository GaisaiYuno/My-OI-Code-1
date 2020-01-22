#include<iostream>
#include<cstdio>
using namespace std;
int m,n,i,j,x,y,c,a[5000][5000];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++)
	a[i][j]=-1;
	for (int i=0;i<n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	if (a[m-1][m]==-1&&a[m][m-1]==-1&&a[m-1][m-1]==-1) cout<<-1<<endl;
	return 0;
}
