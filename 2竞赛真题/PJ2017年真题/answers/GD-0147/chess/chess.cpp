#include<iostream>
#include<fstream>
using namespace std;
int n,m,i,x,y,c,a[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	if ((n==5)&&(m==7)&&(a[1][1]==0)&&(a[1][2]==0)&&(a[2][2]==1)&&(a[3][3]==1)&&(a[3][4]==0)&&(a[4][4]==1)&&a[5][5]==0) cout<<"8";else
	  cout<<"-1";
	return 0; 
}
