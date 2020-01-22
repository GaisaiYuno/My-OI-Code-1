#include<iostream>
#include<cstdio>
using namespace std;

int m,n,a[101][101],f[101][101],t[101][101];

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			a[i][j]=2;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=2147483645;
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	f[1][1]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=2)
			{
				if(f[i-1][j]!=2147483645)
					if(a[i-1][j]==a[i][j]) f[i][j]=min(f[i][j],f[i-1][j]);
					else f[i][j]=min(f[i][j],f[i-1][j]+1);
				if(f[i][j-1]!=2147483645)
					if(a[i][j-1]==a[i][j]) f[i][j]=min(f[i][j],f[i][j-1]);
					else f[i][j]=min(f[i][j],f[i][j-1]+1);
			}
			else 
			{
				if(t[i-1][j]!=1)
					if(f[i-1][j]+2<f[i][j])
					{
						f[i][j]=min(f[i][j],f[i-1][j]+2);
						a[i][j]=a[i-1][j];
						t[i][j]=1;
					}
				if(t[i][j-1]!=1)
					if(f[i][j-1]+2<f[i][j])
					{
						f[i][j]=min(f[i][j],f[i][j-1]+2);
						a[i][j]=a[i][j-1];
						t[i][j]=1;
					}
			}
		}
	if(f[m][m]!=2147483645)	cout<<f[m][m];
	else cout<<-1;
	return 0;
}
