#include <iostream>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cstdlib>
#define INF 2147483647
using namespace std;

struct chess
{
	int x,y,money,col,used;
};
queue <chess> que;

int n,m,Map[105][105],ans,times;
int dx[4]={0,0,1,-1},
	dy[4]={1,-1,0,0};
bool visited[105][105];

void bfs()
{
	que.push((chess){1,1,0,Map[1][1]});
	visited[1][1]=true;
	while (!que.empty())
	{
		if (que.front().x==n&&que.front().y==n)
			ans=min(ans,que.front().money);
		for (int i=0;i<4;i++)
		{
			times++;
			if (times>=6000000) return ;
			int curx=que.front().x+dx[i],cury=que.front().y+dy[i];
			if (curx<1||curx>n||cury<1||cury>n||visited[curx][cury])
				continue;
			
			
			chess tail;
			tail.x=curx;
			tail.y=cury;
			tail.col=Map[curx][cury];
			tail.used=0;
			
			if (que.front().col==INF&&tail.col==INF) continue;
			
			if (que.front().col==tail.col) tail.money=que.front().money;
				else 
				
			if (que.front().col!=INF&&tail.col!=INF) tail.money=que.front().money+1;
				else
						
			if (tail.col==INF)
			{
				if (que.front().used==1) continue;
				tail.money=que.front().money+2;
				tail.used=1;
				tail.col=que.front().col;
			}
			else
			{
				if (que.front().used==1)
				{
					if (que.front().col!=tail.col) 
						tail.money++;
					que.front().used=0;
					tail.used=0;
					que.front().col=INF;
				}
			}

			que.push(tail);
		}
		que.pop();
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a,b;
	ans=INF;
	for (int i=0;i<105;i++)
		for (int j=0;j<105;j++)
		{
			Map[i][j]=INF;
			visited[i][j]=false;
		}
	scanf ("%d%d",&n,&m);
	while (m--)
	{
		int X,Y,Col;
		scanf ("%d%d%d",&X,&Y,&Col);
		Map[X][Y]=Col;
	}
	bfs();	
	if (ans==INF) ans=-1;
	printf ("%d",ans);
	return 0;
}
