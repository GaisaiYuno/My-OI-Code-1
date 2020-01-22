//待拍 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m,n;
int che[101][101];
#define an 1048575
struct Node
{
	int x,y,col;
} que[1048576];
bool in_que[101][101][2];
int dis[101][101][2];
const int fx[5]={0,0,1,0,-1};
const int fy[5]={0,1,0,-1,0};
void spfa();
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	int i,x,y,kind;
	memset(che,255,sizeof che);
	for (i=1;i<=n;++i)
	{
		scanf("%d %d %d",&x,&y,&kind);
		che[x][y]=kind;
	}
	spfa();
	if (che[m][m]>=0)
	{
		if (dis[m][m][che[m][m]]!=dis[0][0][0])
			printf("%d\n",dis[m][m][che[m][m]]);
		else
			printf("-1\n");
	}
	else
	{
		if (dis[m][m][0]!=dis[0][0][0] || dis[m][m][1]!=dis[0][0][0])
			printf("%d\n",min(dis[m][m][0],dis[m][m][1]));
		else
			printf("-1\n");
	}
	return 0;
}
void spfa()
{
	int head=-1,tail=0;
	que[0].x=que[0].y=1;
	que[0].col=che[1][1];
	in_que[1][1][che[1][1]]=1;
	memset(dis,127,sizeof dis);
	dis[1][1][che[1][1]]=0;
	int i,tmp,tx,ty;
	do
	{
		++head&=an;
		for (i=1;i<=4;++i)
		{
			tx=que[head].x+fx[i];
			ty=que[head].y+fy[i];
			if (tx<1 || tx>m || ty<1 || ty>m)
				continue;
			if (che[tx][ty]==-1)//无色 
			{
				if (che[que[head].x][que[head].y]==-1)
					continue;
				if (dis[que[head].x][que[head].y][que[head].col]+2<dis[tx][ty][que[head].col])
				{
					dis[tx][ty][que[head].col]=dis[que[head].x][que[head].y][que[head].col]+2;
					if (!in_que[tx][ty][que[head].col])
					{
						in_que[tx][ty][que[head].col]=1;
						++tail&=an;
						que[tail].x=tx;
						que[tail].y=ty;
						que[tail].col=que[head].col;
					}
				}
				if (dis[que[head].x][que[head].y][que[head].col]+3<dis[tx][ty][que[head].col^1])
				{
					dis[tx][ty][que[head].col^1]=dis[que[head].x][que[head].y][que[head].col]+3;
					if (!in_que[tx][ty][que[head].col^1])
					{
						in_que[tx][ty][que[head].col^1]=1;
						++tail&=an;
						que[tail].x=tx;
						que[tail].y=ty;
						que[tail].col=que[head].col^1;
					}
				}
			}
			else if (que[head].col==che[tx][ty])//颜色相同 
			{
				if (dis[que[head].x][que[head].y][que[head].col]<dis[tx][ty][che[tx][ty]])
				{
					dis[tx][ty][che[tx][ty]]=dis[que[head].x][que[head].y][que[head].col];
					if (!in_que[tx][ty][che[tx][ty]])
					{
						in_que[tx][ty][che[tx][ty]]=1;
						++tail&=an;
						que[tail].x=tx;
						que[tail].y=ty;
						que[tail].col=che[tx][ty];
					}
				}
			}
			else//颜色不同 
			{
				if (dis[que[head].x][que[head].y][que[head].col]+1<dis[tx][ty][che[tx][ty]])
				{
					dis[tx][ty][che[tx][ty]]=dis[que[head].x][que[head].y][que[head].col]+1;
					if (!in_que[tx][ty][che[tx][ty]])
					{
						in_que[tx][ty][che[tx][ty]]=1;
						++tail&=an;
						que[tail].x=tx;
						que[tail].y=ty;
						que[tail].col=che[tx][ty];
					}
				}
			}
		}
		in_que[que[head].x][que[head].y][que[head].col]=1;
	}
	while (head!=tail);
}
