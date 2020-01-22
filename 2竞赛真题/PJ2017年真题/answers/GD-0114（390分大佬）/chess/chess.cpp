#include<cstdio>
#include<cstring>
using namespace std;
int a[1100],b[1100],c[1100];
int g[110][110],f[110][110];
int dx[12]={-1,0,1,0,-1,1,1,-1,-2,0,2,0};
int dy[12]={0,1,0,-1,1,1,-1,-1,0,2,0,-2};
int d[510000][2];bool bk[110][110];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=999999999;
		}
	}
	memset(g,0,sizeof(g));
	memset(bk,true,sizeof(bk));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		g[a[i]][b[i]]=c[i]+1;
	}	
	d[1][0]=1;d[1][1]=1;f[1][1]=0;
	int st=0,ed=1;bk[1][1]=false;
	while(st<ed)
	{
		st++;int x=d[st][0],y=d[st][1];
		for(int i=0;i<=11;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>=1&&xx<=m&&yy>=1&&yy<=m)
			{
				if(i<=3)
				{
					if(g[xx][yy]!=0)
					{
						if(g[xx][yy]!=g[x][y]&&f[xx][yy]>f[x][y]+1)
						{
							f[xx][yy]=f[x][y]+1;
							if(bk[xx][yy]==true)
							{
								bk[xx][yy]=false;
								ed++;
								d[ed][0]=xx;d[ed][1]=yy;
							}
						}
						if(g[xx][yy]==g[x][y]&&f[xx][yy]>f[x][y])
						{
							f[xx][yy]=f[x][y];
							if(bk[xx][yy]==true)
							{
								bk[xx][yy]=false;
								ed++;
								d[ed][0]=xx;d[ed][1]=yy;
							}
						}
					}
					else
					{
						if(f[xx][yy]>f[x][y]+2)
						{
							f[xx][yy]=f[x][y]+2;
						}
					}
				}
				else
				{
					if(g[xx][yy]!=0)
					{
						if(g[xx][yy]!=g[x][y]&&f[xx][yy]>f[x][y]+3)
						{
							f[xx][yy]=f[x][y]+3;
							if(bk[xx][yy]==true)
							{
								bk[xx][yy]=false;
								ed++;
								d[ed][0]=xx;d[ed][1]=yy;
							}
						}
						if(g[xx][yy]==g[x][y]&&f[xx][yy]>f[x][y]+2)
						{
							f[xx][yy]=f[x][y]+2;
							if(bk[xx][yy]==true)
							{
								bk[xx][yy]=false;
								ed++;
								d[ed][0]=xx;d[ed][1]=yy;
							}
						}
					}
				}
			}
		}
		bk[x][y]=true;
	}
	if(f[m][m]==999999999)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",f[m][m]);
	}
	return 0;
}
