#include<iostream>
#include<fstream>
using namespace std;
int x,y,z,a[111][111],c[111][111],n,m;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>x>>y>>z;
		a[x][y]=z+1;
	}
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if (a[i+1][j]<=0&&a[i][j+1]<=0&&a[i][j-1]<=0&&a[i-1][j]==0&&a[i][j]<=0) a[i][j]=-1;
			if (a[i+2][j]<=0&&a[i+1][j+1]<=0&&a[i+1][j-1]<=0&&a[i+1][j]<=0) a[i+1][j]=-1;
			if (a[i-1][j+1]<=0&&a[i+1][j+1]<=0&&a[i][j+2]<=0&&a[i][j+1]<=0) a[i][j+1]=-1;
			if (a[i][j-2]<=0&&a[i+1][j-1]<=0&&a[i-1][j-1]<=0&&a[i][j-1]<=0) a[i][j-1]=-1;
			if (a[i-1][j]<=0&&a[i-1][j-1]<=0&&a[i-1][j+1]<=0&&a[i-1][j]<=0) a[i-1][j]=-1;
		}
	}
	memset(c,125,sizeof(c));
	c[1][1]=0;
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if (i==m&&j==m) 
			{
				if (c[m][m]!=2105376125) cout<<c[m][m];
				else cout<<"-1";
			}
			if (a[i][j]!=-1)
			{
				if (a[i-1][j]!=0)
				{if (a[i-1][j]!=-1)
					if (a[i-1][j]==a[i][j]) c[i-1][j]=min(c[i-1][j],c[i][j]);
					else c[i-1][j]=min(c[i-1][j],c[i][j]+1);
				}
				else 
				{if (a[i-1][j]!=-1)
					if (c[i-1][j]>c[i][j]+2) a[i-1][j]=a[i][j];
					c[i-1][j]=min(c[i-1][j],c[i][j]+2);
				}
				    if (a[i][j-1]!=0)
				    {if (a[i][j-1]!=-1)
				    	if (a[i][j-1]==a[i][j]) c[i][j-1]=min(c[i][j-1],c[i][j]);
				    	else c[i][j-1]=min(c[i][j-1],c[i][j]+1);
			    	}
			    	else 
			    	{if (a[i][j-1]!=-1)
				    	if (c[i][j-1]>c[i][j]+2) a[i][j-1]=a[i][j];
				    	c[i][j-1]=min(c[i][j-1],c[i][j]+2);
			    	}
				if (a[i][j+1]!=0)
				{if (a[i][j+1]!=-1)
					if (a[i][j+1]==a[i][j]) c[i][j+1]=min(c[i][j+1],c[i][j]);
					else c[i][j+1]=min(c[i][j+1],c[i][j]+1);
				}
				else 
				{if (a[i][j+1]!=-1)
					if (c[i][j+1]>c[i][j]+2) a[i][j+1]=a[i][j];
					c[i][j+1]=min(c[i][j+1],c[i][j]+2);
				}
					if (a[i+1][j]!=0)
				    {if (a[i+1][j]!=-1)
				    	if (a[i+1][j]==a[i][j]) c[i+1][j]=min(c[i+1][j],c[i][j]);
				    	else c[i+1][j]=min(c[i+1][j],c[i][j]+1);
				    }
			    	else 
			    	{if (a[i+1][j]!=-1)
				    	if (c[i+1][j]>c[i][j]+2) a[i+1][j]=a[i][j];
				    	c[i+1][j]=min(c[i+1][j],c[i][j]+2);
			    	}
			}
		}
	}
	return 0;
}
