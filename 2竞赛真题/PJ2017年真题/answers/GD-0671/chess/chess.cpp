#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[105][105];
int d[105][105],t_nod[105][105];
int m,n;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(d,-1,sizeof(d));
	memset(t_nod,false,sizeof(t_nod));
	for (int i=1;i<=105;i++)
		for (int j=1;j<=105;j++)
			f[i][j]=1000000;
	scanf("%d%d",&m,&n);
	f[1][1]=0;
	for (int i=0;i<n;i++)
	{
		int X,Y,c;
		scanf("%d%d%d",&X,&Y,&c);
		d[X][Y]=c;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			
			if (d[i][j]==0)
			{
				if (d[i-1][j]==0 && f[i][j]>f[i-1][j]) f[i][j]=f[i-1][j];
				else if (d[i-1][j]==1 && f[i][j]>f[i-1][j]+1) f[i][j]=f[i-1][j]+1;
				
				if (d[i][j-1]==0 && f[i][j]>f[i][j-1]) f[i][j]=f[i][j-1];
				else if (d[i][j-1]==1 && f[i][j]>f[i][j-1]+1) f[i][j]=f[i][j-1]+1;
				
				if (d[i][j+1]==0 && f[i][j]>f[i][j+1]) f[i][j]=f[i][j+1];
				else if (d[i][j+1]==1 && f[i][j]>f[i][j+1]+1) f[i][j]=f[i][j+1]+1;
			
				if (d[i+1][j]==0 && f[i][j]>f[i+1][j]) f[i][j]=f[i+1][j];
				else if (d[i+1][j]==1 && f[i][j]>f[i+1][j]+1) f[i][j]=f[i+1][j]+1;
			}
			if (d[i][j]==1)
			{
				if (d[i-1][j]==1 && f[i][j]>f[i-1][j]) f[i][j]=f[i-1][j];
				else if (d[i-1][j]==0 && f[i][j]>f[i-1][j]+1) f[i][j]=f[i-1][j]+1;
				
				if (d[i][j-1]==1 && f[i][j]>f[i][j-1]) f[i][j]=f[i][j-1];
				else if (d[i][j-1]==0 && f[i][j]>f[i][j-1]+1) f[i][j]=f[i][j-1]+1;
				
				if (d[i][j+1]==1 && f[i][j]>f[i][j+1]) f[i][j]=f[i][j+1];
				else if (d[i][j+1]==0 && f[i][j]>f[i][j+1]+1) f[i][j]=f[i][j+1]+1;
			
				if (d[i+1][j]==1 && f[i][j]>f[i+1][j]) f[i][j]=f[i+1][j];
				else if (d[i+1][j]==0 && f[i][j]>f[i+1][j]+1) f[i][j]=f[i+1][j]+1;
				
			}
			if (d[i][j]==-1)
			{
				if (!t_nod[i-1][j] && f[i][j]>=f[i-1][j]+2) 
				{
					f[i][j]=f[i-1][j]+2;
					d[i][j]=d[i-1][j];
					t_nod[i][j]=true;
				}
				if (!t_nod[i+1][j] && f[i][j]>=f[i+1][j]+2) 
				{
					f[i][j]=f[i+1][j]+2;
					d[i][j]=d[i+1][j];
					t_nod[i][j]=true;
				}
				if (!t_nod[i][j-1] && f[i][j]>=f[i][j-1]+2) 
				{
					f[i][j]=f[i][j-1]+2;
					d[i][j]=d[i][j-1];
					t_nod[i][j]=true;
				}
				if (!t_nod[i][j+1] && f[i][j]>=f[i][j+1]+2) 
				{
					f[i][j]=f[i][j+1]+2;
					d[i][j]=d[i][j+1];
					t_nod[i][j]=true;
				}
			}
		}
	}
	if (f[m][m]==1000000) cout<<-1;
	else cout<<f[m][m];
	return 0;
}
