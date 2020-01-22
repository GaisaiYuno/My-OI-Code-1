#include<iostream>
#include<cstdio>
using namespace std;
int n,o,p,q,a[1000][1000],m,ans,g[1000],h[1000],k,f[1000][1000],d[1000][1000],l;
int x1[4]={0,0,1,-1};
int y1[4]={1,-1,0,0};
void bfs(int x,int y)
{
	g[1]=1;
	h[1]=1;
	k++;
	f[1][1]=1;
	bool du=true;
	for(int j=1;j<=k;j++)
	{
		int d=0;
		if(g[j]==n&&h[j]==n)
		{
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int X=g[j]+x1[i];
			int Y=h[j]+y1[i];
			if(a[X][Y]!=0&&f[X][Y]!=1&&X>=1&&X<=n&&Y>=1&&Y<=n&&f[X][Y]!=2)
			{	
				k++;
				g[k]=X;
				h[k]=Y;
				f[X][Y]=1;
			}
			else d++;
		}
		if(d==4&&f[g[j]][h[j]]!=2)
		{
			for(int i=0;i<4;i++)
			{
				int X=g[j]+x1[i];
				int Y=h[j]+y1[i];
				if(f[X][Y]!=1&&X>=1&&X<=n&&Y>=1&&Y<=n)
				{
					k++;
					a[X][Y]=a[g[j]][h[j]];
					f[X][Y]=2;
					g[k]=X;
					h[k]=Y;
					
				}
			}
		}
		else if(d==4&&f[x][y]==2)
		  return ;
		
	}

}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&p,&q);
		a[o][p]=q+1;
	}
	bfs(1,1);

	d[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(a[i+x1[k]][j+y1[k]]!=0)
				{
					if(f[i+x1[k]][j+y1[k]]==2) d[i+x1[k]][j+y1[k]]=d[i][j]+2;
					else if(a[i+x1[k]][j+y1[k]]!=a[i][j])	
					{
						d[i+x1[k]][j+y1[k]]= d[i+x1[k]][j+y1[k]]+d[i][j]+1;
					}
					else d[i+x1[k]][j+y1[k]]= d[i+x1[k]][j+y1[k]]+d[i][j];
				}
					
			}
		}
	}	

	cout<<d[n][n];
	return 0;
}
