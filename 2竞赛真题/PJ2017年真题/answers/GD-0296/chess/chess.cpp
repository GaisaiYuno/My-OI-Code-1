#include<cstdio>
#include<cstring>

int a[101][101],f[101][101],n,m;;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct node{int x,y,s;}d[10010];

void dfs()
{
	f[1][1]=0;
	d[1].x=1; d[1].y=1; d[1].s=0;
	int tou=1,wei=2;
	while(tou!=wei)
	{
		for(int i=0;i<4;i++)
		{
			int x=dx[i]+d[tou].x;
			int y=dy[i]=d[tou].y;
			if(x>=1&&x<=n&&y>=1&&y<=n)
			{
				if(a[x][y]==a[d[tou].x][d[tou].y])
				{
					if(f[x][y]==-1)
					{
						//printf("1111");
						d[wei].x=x; d[wei].y=y; f[x][y]=f[d[tou].x][d[tou].y]; d[wei].s=0;
						wei++; 
					}
					else if(f[d[tou].x][d[tou].y]<f[x][y])
					{
						d[wei].x=x; d[wei].y=y; f[x][y]=f[d[tou].x][d[tou].y]; d[wei].s=0;
						wei++; 
					}
				}
				else if(a[x][y]==-1&&d[tou].s==0)
				{
					if(f[x][y]==-1)
					{
						d[wei].x=x; d[wei].y=y; f[x][y]=f[d[tou].x][d[tou].y]+2; d[wei].s=1;
						wei++; 
					}
					else if(f[x][y]>(f[d[tou].x][d[tou].y]+2))
					{
						d[wei].x=x; d[wei].y=y; f[x][y]=f[d[tou].x][d[tou].y]+2; d[wei].s=1;
						wei++; 
					}
				}
				else if(a[d[tou].x][d[tou].y]!=a[x][y])
				{
					if(f[x][y]==-1)
					{
						d[wei].x=x; d[wei].y=y; f[x][y]=f[d[tou].x][d[tou].y]+1; d[wei].s=0;
						wei++;
					}
					else if(f[x][y]>(f[d[tou].x][d[tou].y]+1))
					{
						d[wei].x=x; d[wei].y=y; f[x][y]=f[d[tou].x][d[tou].y]+1; d[wei].s=0;
						wei++;
					}
				}
			}
		}
		tou++;
	} 
}

int main()
{
	freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
	memset(a,-1,sizeof(a));
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	dfs();
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}*/
	printf("%d",f[n][n]);
	return 0;
}
/*
freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/
