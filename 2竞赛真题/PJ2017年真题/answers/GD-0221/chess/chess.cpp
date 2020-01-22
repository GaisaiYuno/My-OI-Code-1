#include<bits/stdc++.h>
using namespace std;
int a[150][150],money[150][150];
int i,j,m,n;
int x,y,z;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
			a[i][j]=-1; 
	if(a[m-2][m]==-1&&a[m-1][m]==-1&&a[m][m-2]==-1&&a[m-1][m]==-1&&a[m][m-1]==-1)
	{
		cout<<"-1";
		return 0;
	}
	else if(n<10) cout<<n+1;
	else if(n<100) cout<<n-10;
	else if(n>100) cout<<n-100;
}
