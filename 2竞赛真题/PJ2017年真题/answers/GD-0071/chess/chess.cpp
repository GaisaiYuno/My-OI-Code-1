#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int m,n;
int map[110][110];
int color[110][110];
long long f[110][110];
int fx1[3][3]={{0,0,0},{0,0,1},{0,1,0}};
int fx2[3][3]={{0,0,0},{0,0,1},{0,-1,0}};
int fx3[3][3]={{0,0,0},{0,0,-1},{0,1,0}};
int fx4[3][3]={{0,0,0},{0,0,-1},{0,-1,0}};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	int i,j,k;
	int x,y,c;
	for (i=1;i<=m;++i)
		for (j=1;j<=m;++j)
		{
			map[i][j]=2;
			f[i][j]=2147483647;
		}
	for (i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c;
	}
	memcpy(color,map,sizeof(map));
	int v,xx,yy;
	f[1][1]=0;
	for (i=1;i<=m;++i)
		for (j=1;j<=m;++j)
		{
			x=i;y=j;
			for (k=1;k<=2;++k)
			{
				xx=x+fx1[k][1];
				yy=y+fx1[k][2];
				if(xx>0&&xx<=m&&yy>0&&yy<=m)
				{
					if(map[x][y]==2&&map[xx][yy]==2) continue;
					if(map[xx][yy]==color[x][y]) v=0;
					else if(map[xx][yy]==2) 
					{
						color[xx][yy]=map[x][y];
						v=2;
					}
					else v=1;
					f[xx][yy]=min(f[xx][yy],f[x][y]+v);
				}		
			}
			if(map[x][y]==2) color[x][y]=2;
		}
	for (i=m;i>=1;--i)
		for (j=1;j<=m;++j)
		{
			x=i;y=j;
			for (k=1;k<=2;++k)
			{
				xx=x+fx2[k][1];
				yy=y+fx2[k][2];
				if(xx>0&&xx<=m&&yy>0&&yy<=m)
				{
					if(map[x][y]==2&&map[xx][yy]==2) continue;
					if(map[xx][yy]==color[x][y]) v=0;
					else if(map[xx][yy]==2) 
					{
						color[xx][yy]=map[x][y];
						v=2;
					}
					else v=1;
					f[xx][yy]=min(f[xx][yy],f[x][y]+v);
				}		
			}
			if(map[x][y]==2) color[x][y]=2;
		}
	for (i=1;i<=m;++i)
		for (j=m;j>=1;--j)
		{
			x=i;y=j;
			for (k=1;k<=2;++k)
			{
				xx=x+fx3[k][1];
				yy=y+fx3[k][2];
				if(xx>0&&xx<=m&&yy>0&&yy<=m)
				{
					if(map[x][y]==2&&map[xx][yy]==2) continue;
					if(map[xx][yy]==color[x][y]) v=0;
					else if(map[xx][yy]==2) 
					{
						color[xx][yy]=map[x][y];
						v=2;
					}
					else v=1;
					f[xx][yy]=min(f[xx][yy],f[x][y]+v);
				}		
			}
			if(map[x][y]==2) color[x][y]=2;
		}
	for (i=m;i>=1;--i)
		for (j=m;j>=1;--j)
		{
			x=i;y=j;
			for (k=1;k<=2;++k)
			{
				xx=x+fx4[k][1];
				yy=y+fx4[k][2];
				if(xx>0&&xx<=m&&yy>0&&yy<=m)
				{
					if(map[x][y]==2&&map[xx][yy]==2) continue;
					if(map[xx][yy]==color[x][y]) v=0;
					else if(map[xx][yy]==2) 
					{
						color[xx][yy]=map[x][y];
						v=2;
					}
					else v=1;
					f[xx][yy]=min(f[xx][yy],f[x][y]+v);
				}		
			}
			if(map[x][y]==2) color[x][y]=2;
		}
	if(f[m][m]!=2147483647) printf("%lld\n",f[m][m]);
	else printf("-1\n");
}
