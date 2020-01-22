#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int m,n,a[105][105],u[4][2]={{1,0},{0,1},{-1,0},{0,-1}},sum=500000;
bool p[105][105];
int dfs(int x,int y,int ry,int mo,int cost)
{
	if(x==m&&y==m)
	{
		sum=min(sum,cost);
		
		return 0;	
	}
	if(x>m||y>m)
	return 0;
	for(int i=0;i<=3;i++)
	{
		if(x+u[i][0]>0&&y+u[i][1]>0)
		{
			if(a[x+u[i][0]][y+u[i][1]]==ry&&p[x+u[i][0]][y+u[i][1]]==0)
			{
				p[x+u[i][0]][y+u[i][1]]=1;
				dfs(x+u[i][0],y+u[i][1],ry,0,cost);
				p[x+u[i][0]][y+u[i][1]]=0;
			}
			else
			{
				if(a[x+u[i][0]][y+u[i][1]]==-1&&p[x+u[i][0]][y+u[i][1]]==0)
				{
					if(mo==0)
					{
						p[x+u[i][0]][y+u[i][1]]=1;
						dfs(x+u[i][0],y+u[i][1],ry,1,cost+2);
						p[x+u[i][0]][y+u[i][1]]=0;
					}
				}
				else
				{
					if(p[x+u[i][0]][y+u[i][1]]==0)
					{
						p[x+u[i][0]][y+u[i][1]]=1;
						dfs(x+u[i][0],y+u[i][1],(ry+1)%2,0,cost+1);
						p[x+u[i][0]][y+u[i][1]]=0;	
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		a[i][j]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		int x1,y1,c;
		cin>>x1>>y1>>c;
		a[x1][y1]=c;
	}
	dfs(1,1,a[1][1],0,0);
	if(sum==500000)
	cout<<-1;
	else
	cout<<sum;
	return 0;
}
