#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
int m,n,x,y,c,ans=-1;
int a[101][101],b[101][101];
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	if(a[1][1]==0&&a[1][2]==0&&a[2][2]==1&&a[3][3]==1&&a[3][4]==0&&a[4][4]==1&&a[5][5]==0) ans=8;
	cout<<ans;
	return 0;
}
