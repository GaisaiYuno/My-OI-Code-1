#include <cstdio>
#include <cstring>
#include <queue>
#define MIN(A,B) (A<B?A:B)
using namespace std;

struct tnode
{
	int x,y,col,coin,mag;
};
queue <tnode> Que;
int Map[1005][1005];
int n,m;
int dx[5]={0,1},
	dy[5]={1,0};

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(Map,-1,sizeof(Map));
	scanf("%d%d",&n,&m);
	for(int i=1,X,Y,c; i<=m; i++)
	{
		scanf("%d%d%d",&X,&Y,&c);
		Map[X][Y]=c;
	}
	if(n==1)
	{
		printf("0");
		return 0;
	}
	tnode tmp={1,1,Map[1][1],0,0};
	Que.push(tmp);
	int ans=214748364;
	while(!Que.empty())
	{
		tmp=Que.front();
		Que.pop();
		for(int i=0; i<2; i++)
		{
			int curx=tmp.x+dx[i],cury=tmp.y+dy[i];
			if(curx<=n&&cury<=n)
			{
				if(Map[curx][cury]==tmp.col)
				{
					tnode t1={curx,cury,tmp.col,tmp.coin,0};
					Que.push(t1);
					if(curx==n&&cury==n)
						ans=MIN(ans,tmp.coin);
				}else
				if(Map[curx][cury]!=-1)
				{
					tnode t1={curx,cury,Map[curx][cury],tmp.coin+1,0};
					Que.push(t1);
					if(curx==n&&cury==n)
						ans=MIN(ans,tmp.coin+1);
				}else
				if(tmp.mag==0)
				{
					tnode t1={curx,cury,tmp.col,tmp.coin+2,1};
					Que.push(t1);
					if(curx==n&&cury==n)
						ans=MIN(ans,tmp.coin+2);
				}
			}
		}
	}
	if(ans==214748364)	printf("-1");
	else	printf("%d",ans);
	return 0;
}
