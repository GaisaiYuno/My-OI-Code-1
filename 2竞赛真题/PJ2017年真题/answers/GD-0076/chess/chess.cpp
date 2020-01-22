#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[100+10][100+10],x,y,c,f[100+10][100+10];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,0,sizeof(0));
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
	f[1][1]=0;
	for(int i=2;i<=m;i++)
	{
		if(f[1][i-1]==-1)
		{
			f[1][i]=-1;
			continue;
		}
		if(a[1][i]==0&&a[1][i-1]==0) f[1][i]=-1;
		else
		{
			if(a[1][i]==0||a[1][i-1]==0)
			{
				if(a[1][i]==0) f[1][i]=f[1][i-1]+2;
				else
				{
					if(a[1][i]!=a[1][i-2]) f[1][i]++;
					f[1][i]+=f[1][i-1];
				}
			}
			else
			{
				if(a[1][i]==a[1][i-1]) f[1][i]==f[1][i-1];
				else f[1][i]=f[1][i-1]+1;
			}
		}
	}
	for(int i=2;i<=m;i++)
	{
		if(f[i-1][1]==-1)
		{
			f[i-1][1]=-1;
			continue;
		}
		if(a[i][1]==0&&a[i-1][1]==0) f[i][1]=-1;
		else
		{
			if(a[i][1]==0||a[i-1][1]==0)
			{
				if(a[i][1]==0) f[i][1]=f[i-1][1]+2;
				else
				{
					if(a[i][1]!=a[i-2][1]) f[i][1]++;
					f[i][1]+=f[i-1][1];
				}
			}
			else
			{
				if(a[i][1]==a[i-1][1]) f[i][1]=f[i-1][1];
				else f[i][1]=f[i-1][1]+1;
			}
		}
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(f[i-1][j]==-1&&f[i][j-1]==-1) f[i][j]=-1;
			else
			{
				if(f[i-1][j]==-1||f[i][j-1]==-1)
				{
					if(f[i-1][j]==-1)
					{
						if(a[i][j-1]==0&&a[i][j]==0) f[i][j]=-1;
						else
						{
							if(a[i][j-1]==0||a[i][j]==0)
							{
								if(a[i][j]==0) f[i][j]=f[i][j-1]+2;
								else
								{
									if(a[i][j]!=a[i-1][j-1]) f[i][j]++;
									f[i][j]+=f[i][j-1];
								}
							}
							else
							{
								if(a[i][j-1]==a[i][j]) f[i][j]=f[i][j-1];
								else f[i][j]=f[i][j-1]+1;
							}
						}
					}
					else
					{
						if(a[i-1][j]==0&&a[i][j]==0) f[i][j]=-1;
						else
						{
							if(a[i-1][j]==0||a[i][j]==0)
							{
								if(a[i][j]==0) f[i][j]=f[i-1][j]+2;
								else
								{
									if(a[i][j]!=a[i-1][j-1]) f[i][j]++;
									f[i][j]+=f[i-1][j];
								}
							}
							else
							{
								if(a[i-1][j]==a[i][j]) f[i][j]=f[i-1][j];
								else f[i][j]=f[i-1][j]+1;
							}
						}
					}
				}
				else
				{
					int ans1=0,ans2=0;
					if(a[i-1][j]==0&&a[i][j]==0) ans1=-1;
					else
					{
						if(a[i-1][j]==0||a[i][j]==0)
						{
							if(a[i][j]==0) ans1=f[i-1][j]+2;
							else
							{
								if(a[i][j]!=a[i-1][j-1]) ans1++;
								ans1+=f[i-1][j];
							}
						}
						else
						{
							if(a[i][j]==a[i-1][j]) ans1=f[i-1][j];
							else ans1=f[i-1][j]+1;
						}
					}
					if(a[i][j-1]==0&&a[i][j]==0) ans2=-1;
					else
					{
						if(a[i][j-1]==0||a[i][j]==0)
						{
							if(a[i][j]==0) ans2=f[i][j-1]+2;
							else
							{
								if(a[i][j]!=a[i][j-1]) ans2++;
								ans2+=f[i][j-1];
							}
						}
						else
						{
							if(a[i][j]==a[i][j-1]) ans2=f[i][j-1];
							else ans2=f[i][j-1]+1;
						}
					}
					f[i][j]=min(ans1,ans2);				
				}
			}
		}
	}
	cout<<f[m][m]<<endl;
	return 0;
}
