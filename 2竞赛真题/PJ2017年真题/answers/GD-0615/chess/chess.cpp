#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

int n,m,a[105][105],f[105][105],t[105][105],ans=2147483647;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

bool judge(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=n;
}

void dfs(int x,int y,int cost)
{
	f[x][y]=cost;
	if(x==n&&y==n)
	{
		ans=min(ans,cost);
		return;
	}
	for(int i=0;i<4;++i)
	{
		int nowx=x+dx[i],nowy=y+dy[i];
		if(judge(nowx,nowy))
		{
			if(a[x][y]==0)
			{
				if(a[nowx][nowy]==0)continue;
				if(a[nowx][nowy]==t[x][y])
				{
					if(f[nowx][nowy]>cost)
						dfs(nowx,nowy,cost);
				}
				else
				{
					if(f[nowx][nowy]>cost+1)
						dfs(nowx,nowy,cost+1);
				}
			}
			else
			{
				if(a[nowx][nowy]==0)
				{
					if(t[nowx][nowy])continue;
					if(f[nowx][nowy]>cost+2)
					{
						t[nowx][nowy]=a[x][y];
						dfs(nowx,nowy,cost+2);
						t[nowx][nowy]=0;
					}
				}
				else
				{
					if(a[nowx][nowy]==a[x][y])
					{
						if(f[nowx][nowy]>cost)dfs(nowx,nowy,cost);
					}
					else
					{
						if(f[nowx][nowy]>cost+1)dfs(nowx,nowy,cost+1);
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)f[i][j]=100000000;
	dfs(1,1,0);
	printf("%d\n",ans==2147483647?-1:ans);
}
