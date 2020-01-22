#include <iostream>
#include <cstdio>
#include <string>
#define oo 3000000
using namespace std;
int n,m,f[101][101],fl[101][101];
int find(int x,int y)
{
	int sum1=fl[x-1][y],sum2=fl[x][y-1];
	if(f[x][y]==-1)
	{
		if(f[x-1][y]==-1||f[x-1][y]==10||f[x-1][y]==11||fl[x-1][y]==-1)
		{
			if(f[x][y-1]==-1||f[x][y-1]==10||f[x][y-1]==11||fl[x][y-1]==-1) return -1;
			else
			{
				f[x][y]=f[x][y-1]+10;
				return sum2+2;
			}
		}
		else
		if(f[x][y-1]==-1||f[x][y-1]==10||f[x][y-1]==11||fl[x][y-1]==-1)
		{
			f[x][y]=f[x-1][y]+10;
			return sum1+2;
		}
		else
		{
			if(sum2>sum1)
			{
				f[x][y]=f[x][y-1]+10;
				return sum2+2;
			}
			else
			{
				f[x][y]=f[x-1][y]+10;
				return sum1+2;
			}
		}
	}
	else
	if(f[x][y]==0)
	{
		if(fl[x-1][y]==-1)
		{
			if(fl[x][y-1]==-1) return -1;
			else
			{
				if(f[x][y-1]==0||f[x][y-1]==10) return sum2;
				else return sum2+1;
			}
		}
		else
		if(fl[x][y-1]==-1)
		{
			if(f[x-1][y]==0||f[x-1][y]==10) return sum1;
			else return sum1+1;
		}
		else
		{
			if(f[x][y-1]==1||f[x][y-1]==11) sum2++;
			if(f[x-1][y]==1||f[x-1][y]==11) sum1++;
			return min(sum1,sum2);
		}
	}
	else
	{
		if(fl[x-1][y]==-1)
		{
			if(fl[x][y-1]==-1) return -1;
			else
			{
				if(f[x][y-1]==1||f[x][y-1]==11) return sum2;
				else return sum2+1;
			}
		}
		else
		if(fl[x][y-1]==-1)
		{
			if(f[x-1][y]==1||f[x-1][y]==11) return sum1;
			else return sum1+1;
		}
		else
		{
			if(f[x-1][y]==0||f[x-1][y]==10) sum1++;
			if(f[x][y-1]==0||f[x][y-1]==10) sum2++;
			return min(sum1,sum2);
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[i][j]=-1,fl[i][j]=-1;
	for(int a,b,c,i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		f[a][b]=c;
	}
	fl[1][1]=0;
	for(int j=2;j<=n;j++) fl[1][j]=find(1,j),fl[j][1]=find(j,1);
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			fl[i][j]=find(i,j);
	cout<<fl[n][n];
	return 0;
}
