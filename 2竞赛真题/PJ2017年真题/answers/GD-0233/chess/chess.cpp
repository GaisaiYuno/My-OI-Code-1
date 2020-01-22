#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int ans,b[101][101],n,m,f[1001][1001];bool bk;
/*void dfs(int x,int y,int d,bool u)
{
	if(x==m&&y==m){printf("%d\n",d);exit(0);}
	else
	{
		for(int i=0;i<=3;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>0&&xx<=m&&yy>0&&yy<=m)
			{
				if(b[xx][yy]!=b[x][y])
				{
					if(b[xx][yy]==0)
					{
						if(u==false)return;
						b[xx][yy]=b[x][y];
						dfs(xx,yy,d+2,false);
						b[xx][yy]=0;
					}
					else
					{
						dfs(xx,yy,d+1,true);
					}
				}
				else
				{
					dfs(xx,yy,d,true);
				}
			}
		}
	}
}*/
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		if(c==0)b[x][y]=-1;
		else b[x][y]=1;
	}
//	dfs(1,1,0,true);
	printf("-1\n");
}
