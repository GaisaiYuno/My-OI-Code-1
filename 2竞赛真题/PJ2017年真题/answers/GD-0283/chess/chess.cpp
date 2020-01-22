#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define oo 2000000000LL

using namespace std;

const int dx[4]={0,0,1,-1};
const int dy[4]={-1,1,0,0};

struct Node{
	int x,y,ans,IsChange;
};

queue <Node> q;

int n,m,map[105][105],Ans=-1;
bool vis[105][105];

void bfs()
{
	q.push((Node){1,1,0,-1});
	vis[1][1]=true;
	while (!q.empty())
	{
		Node cur=q.front();
		q.pop();
		if (cur.x==n&&cur.y==n)
		{
			Ans=cur.ans;
			return;
		}
		for (int i=0;i<4;i++)
		{
			int nowx=cur.x+dx[i],nowy=cur.y+dy[i];
			if (nowx<1||nowx>n||nowy<1||nowy>n||vis[nowx][nowy]||(cur.IsChange>-1&&!map[nowx][nowy])) continue;
			vis[nowx][nowy]=true;
			if (cur.IsChange==-1)
			{
				if (!map[nowx][nowy]) q.push((Node){nowx,nowy,cur.ans+2,map[cur.x][cur.y]}); else
				if (map[nowx][nowy]==map[cur.x][cur.y]) q.push((Node){nowx,nowy,cur.ans,-1}); else
					q.push((Node){nowx,nowy,cur.ans+1,-1});
			}else
			{
				if (map[nowx][nowy]==cur.IsChange) q.push((Node){nowx,nowy,cur.ans,-1}); else
					q.push((Node){nowx,nowy,cur.ans+1,-1});
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,color;
		scanf("%d%d%d",&a,&b,&color);
		map[a][b]=color+1;//0:no color 1:red 2:yellow
	}
	bfs();
	printf("%d\n",Ans);
	return 0;
}
