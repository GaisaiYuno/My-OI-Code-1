#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

void readin()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}

int minn=2139062143,m,n;
bool vis[150][150];
int map[150][150];

bool check(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=m&&vis[x][y]==false)
		return true;
	return false;
}

void hehe(int x,int y,int magic,int ans)
{
	if(x==m&&y==m)
	{
		minn=min(ans,minn);
		return;
	}
	vis[x][y]=true;
	if(check(x-1,y))
	{
		if(map[x-1][y]!=-1)
			if(map[x-1][y]==map[x][y])
			{
				hehe(x-1,y,0,ans);
			}
			else
			{
				hehe(x-1,y,0,ans+1);
			}
		else
		if(map[x-1][y]==-1&&magic==0)
		{
			map[x-1][y]=map[x][y];
			hehe(x-1,y,1,ans+2);
			map[x-1][y]=-1;
		}
	}
	if(check(x,y+1))
	{
		if(map[x][y+1]!=-1)
			if(map[x][y+1]==map[x][y])
			{
				hehe(x,y+1,0,ans);
			}
			else
			{
				hehe(x,y+1,0,ans+1);
			}
		else
		if(map[x][y+1]==-1&&magic==0)
		{
			map[x][y+1]=map[x][y];
			hehe(x,y+1,1,ans+2);
			map[x][y+1]=-1;
		}
	}
	if(check(x+1,y))
	{
		if(map[x+1][y]!=-1)
			if(map[x+1][y]==map[x][y])
			{
				hehe(x+1,y,0,ans);
			}
			else
			{
				hehe(x+1,y,0,ans+1);
			}
		else
		if(map[x+1][y]==-1&&magic==0)
		{
			map[x+1][y]=map[x][y];
			hehe(x+1,y,1,ans+2);
			map[x+1][y]=-1;
		}
	}
	if(check(x,y-1))
	{
		if(map[x][y-1]!=-1)
			if(map[x][y-1]==map[x][y])
			{
				hehe(x,y-1,0,ans);
			}
			else
			{
				hehe(x,y-1,0,ans+1);
			}
		else
		if(map[x][y-1]==-1&&magic==0)
		{
			map[x][y-1]=map[x][y];
			hehe(x,y-1,1,ans+2);
			map[x][y-1]=-1;
		}
	}
	vis[x][y]=false;
}

int main()
{
	readin();
	int x,y,col;
	scanf("%d%d",&m,&n);
	if(m>20)
	{
		puts("-1");
		return 0;
	}
	memset(map,-1,sizeof(map));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&col);
		map[x][y]=col;
	}
	hehe(1,1,0,0);
	if(minn==2139062143)
		puts("-1");
	else
		printf("%d\n",minn);
	return 0;
}
