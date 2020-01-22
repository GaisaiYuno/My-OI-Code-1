#include<cstdio>
#include<cstring>

int n,k;
int c[2100][2100];
int f[2100][2100];

int minn(int x,int y) { return x<y?x:y; }

int dt(int x,int y,int t,int co)
{
	if(x==1 && y==1) return 0;
	int x1=x-1,y1=y-1;
	if(x1>=1)
	{
		if(co!=-1)
		{
			if(c[x1][y]==co) f[x][y]=minn( f[x][y] , dt(x1,y,1,c[x1][y]) );
			else if(c[x1][y]!=-1) f[x][y]=minn( f[x][y] , dt(x1,y,1,c[x1][y])+1 );
			else if(t==1)
			{
				f[x][y]=minn( f[x][y] , dt(x1,y,0,co)+2 );
			}
		}
		else f[x][y]=minn( f[x][y] , dt(x1,y,0,c[x1][y])+2 );
	}
	if(y1>=1)
	{
		if(co!=-1)
		{
			if(c[x][y1]==co) f[x][y]=minn( f[x][y] , dt(x,y1,1,c[x][y1]) );
			else if(c[x][y1]!=-1) f[x][y]=minn( f[x][y] , dt(x,y1,1,c[x][y1])+1 );
			else if(t==1)
			{
				f[x][y]=minn( f[x][y] , dt(x,y1,0,co)+2 );
			}
		}
		else f[x][y]=minn( f[x][y] , dt(x,y1,0,c[x][y1])+2 );
	}
	return f[x][y];
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	memset(c,-1,sizeof(c));
	
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=999999999;
	for(int i=1;i<=k;i++)
	{
		int x,y,cc; scanf("%d %d %d",&x,&y,&cc);
		c[x][y]=cc;
	}
	
	int ans=999999999;
	if(c[n][n]!=-1) ans=minn(ans , dt(n,n,1,c[n][n]));
	else ans=minn(ans , dt(n,n,0,c[n][n]));
	
	if(ans!=999999999) printf("%d",ans);
	else printf("-1");
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

8

5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0

-1
*/
