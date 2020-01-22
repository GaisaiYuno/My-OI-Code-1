#include<cstdio>
#include<cstring>

int n,m;
int a[510][510],b[510][501];
int d[1010],s=0,sum=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs2(int l,int r)
{
	int x=l,y=r,m=d[(x+y)/2];
	while(x<=y)
	{
		while(d[x]<m)x++;
		while(d[y]>m)y--;
		if(x<=y)
		{
			int t=d[x];d[x]=d[y];d[y]=t;
			x++;y--;
		}
	}
	if(l<y)dfs2(l,y);
	if(x<r)dfs2(x,r);
}

void dfs(int x,int y,int kk)
{
	if(x==n&&y==n)
	{
		s++;d[s]=sum;
		
		return ;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(b[xx][yy]==0&&xx<=n&&xx>=1&&yy>=1&&yy<=n)
			{
				if(a[xx][yy]!=a[x][y])
				{
					if(a[xx][yy]>0)
					{
						sum+=1;b[xx][yy]=1;
						dfs(xx,yy,0);
						sum-=1;b[xx][yy]=0;
					}
					else if(a[xx][yy]==0&&kk==0)
					{
						sum+=2;b[xx][yy]=1;a[xx][yy]=a[x][y];
						dfs(xx,yy,1);
						sum-=2;b[xx][yy]=0;a[xx][yy]=0;
					}	
				}
				else if(a[xx][yy]==a[x][y])
				{
					b[xx][yy]=1;
					dfs(xx,yy,0);
					b[xx][yy]=0;
				}
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(c==1)a[x][y]=1;
		if(c==0)a[x][y]=2;
	}
	dfs(1,1,0);
	if(s==0)
	{
		printf("-1\n");return 0;
	}
	dfs2(1,s);
	printf("%d",d[1]);
}
