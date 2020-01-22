#include <iostream>
#include <cstdio>
#define oo 21474836
using namespace std;
int m,n,a[110][110],f[110][110],x,y,z;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=0;i<=105;i++)
	  for (int j=0;j<=105;j++)
	  a[i][j]=-1;
	for (int i=1;i<=n;i++)
	{
	  cin>>x>>y>>z;
	  a[x][y]=z;
    }
    for (int i=1;i<=m;i++)
      for (int j=1;j<=m;j++)
      {
      	 if (a[i-1][j-1]==-1&&a[i-1][j]==-1&&a[i][j-1]==-1) f[i][j]=oo;
      }
    f[1][1]=0;
    if (f[m][m]==oo) {cout<<-1;return 0;}
    for (int i=1;i<=m;i++)
      for (int j=1;j<=m;j++)
      {
      	 if (a[i][j]==a[i][j-1]&&a[i][j]==a[i-1][j]&&f[i][j]!=oo) f[i][j]=min(f[i][j-1],f[i-1][j]);
      	 if (a[i][j]==a[i][j-1]&&a[i][j]!=a[i-1][j]&&f[i][j]!=oo) f[i][j]=min(f[i][j-1],f[i-1][j]+1);
      	 if (a[i][j]!=a[i][j-1]&&a[i][j]==a[i-1][j]&&f[i][j]!=oo) f[i][j]=min(f[i][j-1]+1,f[i-1][j]);
      	 if (a[i][j]!=a[i][j-1]&&a[i][j]!=a[i-1][j]&&f[i][j]!=oo) f[i][j]=min(f[i][j-1]+2,f[i-1][j]+2);
      }
    cout<<f[m][m]+1;
	return 0;
}
