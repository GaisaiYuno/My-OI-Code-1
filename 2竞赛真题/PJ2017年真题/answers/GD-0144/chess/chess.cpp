#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,map[101][101],ans=-1,x2,y2,col;
bool check[101][101];
void dfs(int x,int y,int cost,bool do_magic)
{
	check[x][y]=true;
	int k=map[x][y];
	if (!do_magic)
	{
		map[x][y]=-1;
	}
	if (x>=m&&y>=m)
	{
		if (ans==-1) ans=cost;
		ans=min(ans,cost);
		return;
	}
	if (x-1>0&&!check[x-1][y])
	{
		if (map[x-1][y]!=-1)
		{
			dfs(x-1,y,cost+abs(k-map[x-1][y]),true);
			check[x-1][y]=false;
		}
		if (map[x-1][y]==-1&&do_magic)
		{
			map[x-1][y]=k;
			dfs(x-1,y,cost+2,false);
			map[x-1][y]=(k+1)%2;
			dfs(x-1,y,cost+3,false);
			check[x-1][y]=false;
		}
	}
	if (x+1<=m&&!check[x+1][y])
	{
		if (map[x+1][y]!=-1)
		{
			dfs(x+1,y,cost+abs(k-map[x+1][y]),true);
			check[x+1][y]=false;
		}
		if (map[x+1][y]==-1&&do_magic)
		{
			map[x+1][y]=k;
			dfs(x+1,y,cost+2,false);
			map[x+1][y]=(k+1)%2;
			dfs(x+1,y,cost+3,false);
			check[x+1][y]=false;
		}
	}
	if (y-1>0&&!check[x][y-1])
	{
		if (map[x][y-1]!=-1)
		{
			dfs(x,y-1,cost+abs(k-map[x][y-1]),true);
			check[x][y-1]=false;
		}
		if (map[x][y-1]==-1&&do_magic)
		{
			map[x][y-1]=k;
			dfs(x,y-1,cost+2,false);
			map[x][y-1]=(k+1)%2;
			dfs(x,y-1,cost+3,false);
			check[x][y-1]=false;
		}
	}
	if (y+1<=m&&!check[x][y+1])
	{
		if (map[x][y+1]!=-1)
		{
			dfs(x,y+1,cost+abs(k-map[x][y+1]),true);
			check[x][y+1]=false;
		}
		if (map[x][y+1]==-1&&do_magic)
		{
			map[x][y+1]=k;
			dfs(x,y+1,cost+2,false);
			map[x][y+1]=(k+1)%2;
			dfs(x,y+1,cost+3,false);
			check[x][y+1]=false;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	memset(map,-1,sizeof(map));
	memset(check,false,sizeof(check));
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x2,&y2,&col);
		map[x2][y2]=col;
	}
	dfs(1,1,0,true);
	cout<<ans;
	return 0;
}
