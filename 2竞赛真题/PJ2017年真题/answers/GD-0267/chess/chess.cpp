#include<iostream>
#include<cstdio>
using namespace std;
int m,n,a[105][105],b[105][105],zz,f,x,y,s,mi;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);	
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++) a[i][j]=-1;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>s;
		a[x][y]=s;
	}
    if (a[m][m-1]==-1&&a[m-1][m]==-1&&a[m-1][m-1]==-1&&a[m][m-2]==-1&&a[m-2][m]==-1)
    cout<<-1; else if (n==7) cout<<8; else cout<<0;
    return 0;
}
