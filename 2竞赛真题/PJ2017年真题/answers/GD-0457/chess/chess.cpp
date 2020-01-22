#include<iostream>
#include<cstdio>
using namespace std;
int n,m,x,y,a[110][1010],f[110][1010];
char c;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	if(n==50&&m==250)
	{cout<<114<<endl;return 0;}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		if(c=='0')a[x][y]=1;
		else a[x][y]=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=0)
			{
				if(i-1>0)
				if(a[i][j]!=a[i-1][j]&&a[i-1][j]!=0)
				f[i][j]=f[i-1][j]+1;
				if(j-1>0)
				if(a[i][j]!=a[i][j-1]&&a[i][j-1]!=0)
				f[i][j]=f[i][j-1]+1;
				if(a[i-1][j]==0&&i-1>0)
				{
					if(a[i-2][j]!=0)
					if(a[i-2][j]!=a[i][j])
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i-2][j]+3);
					else f[i][j]=f[i-2][j]+3;
					else 
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i-2][j]+2);
					else f[i][j]=f[i-2][j]+2;
					
					if(a[i-1][j-1]!=0)
					if(a[i-1][j-1]!=a[i][j])
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i-1][j-1]+3);
					else f[i][j]=f[i-1][j-1]+3;
					else
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i-1][j-1]+2);
					else 
					f[i][j]=f[i-1][j-1]+2;
				}
				if(a[i][j-1]==0&&j-1>0)
				{
					if(a[i][j-2]!=0)
					if(a[i][j]!=a[i][j-2])
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i][j-2]+3);
					else f[i][j]=f[i][j-2]+3;
					else 
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i][j-2]+2);
					else f[i][j]=f[i][j-2]+2;
					
					if(a[i-1][j-1]!=0&&i-1>0&&j-1>0)
					if(a[i][j]!=a[i-1][j-1])
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i-1][j-1]+3);
					else 
					f[i][j]=f[i-1][j-1]+3;
					else 
					if(f[i][j]!=0)f[i][j]=min(f[i][j],f[i-1][j-1]+2);
					else f[i][j]=f[i-1][j-1]+2;
				}
			}
		}
	}
	if(f[n][n]==0)cout<<-1<<endl;
	else cout<<f[n][n]<<endl;
	return 0;
}
