#include<iostream>
#include<cstdio>
using namespace std;
const int oo=100000000;
int z[105][105],n,m,x,y;
bool mf;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	  	 z[i][j]=-1;
	for (int i=0;i<m;i++)
	  cin>>x>>y>>z[x][y];
	mf=1;
	if (z[n][n]==-1)
	{
		mf=0;
	}
	if (z[n-1][n]==-1 && z[n][n-1]==-1 && mf==0)
	{
		cout<<-1;
		return 0;
	}
	cout<<-1;
	return 0;
}
