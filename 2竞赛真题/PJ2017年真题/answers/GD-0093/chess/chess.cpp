#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> p;
queue<p> que;
int m,n;
int bz[101][101];
int dis[101][101];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	p tmp;
	int x,y,c,xx,yy;
	memset(bz,-1,sizeof bz);
	memset(dis,0x2a,sizeof dis);
	scanf("%d%d",&m,&n);
	while (n--)
	{
		scanf("%d%d%d",&x,&y,&c);
		bz[x][y]=c;
	}
	dis[1][1]=0;
	que.push((p){1,1});
	while (!que.empty())
	{
		tmp=que.front();
		que.pop();
		for (int i=0;i<4;i++)
		{
			x=tmp.first+dx[i];
			y=tmp.second+dy[i];
			if (!(x>0&&x<=m&&y>0&&y<=m))
				continue;
			if (bz[x][y]==-1)
				for (int j=0;j<4;j++)
				{
					xx=x+dx[j];
					yy=y+dy[j];
					if (!(xx>0&&xx<=m&&yy>0&&yy<=m))
						continue;
					if (bz[xx][yy]==-1||xx==tmp.first&&yy==tmp.second)
						continue;
					if (bz[xx][yy]==bz[tmp.first][tmp.second])
					{
						if (dis[xx][yy]>dis[tmp.first][tmp.second]+2)
						{
							dis[xx][yy]=dis[tmp.first][tmp.second]+2;
							que.push((p){xx,yy});
						}
					}
					else
					{
						if (dis[xx][yy]>dis[tmp.first][tmp.second]+3)
						{
							dis[xx][yy]=dis[tmp.first][tmp.second]+3;
							que.push((p){xx,yy});
						}
					}
				}
			else
				if (bz[x][y]==bz[tmp.first][tmp.second])
				{
					if (dis[x][y]>dis[tmp.first][tmp.second])
					{
						dis[x][y]=dis[tmp.first][tmp.second];
						que.push((p){x,y});
					}
				}
				else
					if (dis[x][y]>dis[tmp.first][tmp.second]+1)
					{
						dis[x][y]=dis[tmp.first][tmp.second]+1;
						que.push((p){x,y});
					}
		}
	}
	if (dis[m][m]==0x2a2a2a2a)
		puts("-1");
	else
		printf("%d\n",dis[m][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
