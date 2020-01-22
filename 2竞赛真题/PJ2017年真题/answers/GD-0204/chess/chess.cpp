#include <cstdio>
#include <queue>

using namespace std;

#define INF 1000000000

const int wayx[4]={-1, 1, 0, 0},
		  wayy[4]={ 0, 0,-1, 1};

queue<int> q;

int n,m,chess[105][105],cnum,color[105][105],len[1005][1005],dis[1005],fx,fy,tx,ty,cost;
bool IN[1005];

void MarkColor(int x,int y,int sign,int c)
{
	if (x<1 || x>n || y<1 || y>n || chess[x][y]!=sign || color[x][y]!=0)
		return;
	color[x][y]=c;
	for (int i=0;i<4;i++)
		MarkColor(x+wayx[i],y+wayy[i],sign,c);
	return;
}

void SPFA()
{
	q.push(1);
	dis[1]=0;
	IN[1]=true;
	
	while (!q.empty())
	{
		int x=q.front();
		
		for (int y=1;y<=cnum;y++)
			if (x!=y&&dis[x]+len[x][y]<dis[y])
			{
				dis[y]=dis[x]+len[x][y];
				if (!IN[y])
				{
					IN[y]=true;
					q.push(y);
				}
			}
		
		q.pop();
		IN[x]=false;
	}
	
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			chess[i][j]=-1;
	
	for (int i=1,x,y,c;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		chess[x][y]=c;
	}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (color[i][j]==0&&chess[i][j]!=-1)
			{
				MarkColor(i,j,chess[i][j],++cnum);
				dis[cnum]=INF;
			}
	
	for (int i=1;i<=cnum;i++)
		for (int j=1;j<=cnum;j++)
			len[i][j]=INF;
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (color[i][j]==0)
				for (int k=0;k<4;k++)
				{
					fx=i+wayx[k],fy=j+wayy[k];
					if (fx<1 || fx>n || fy<1 || fy>n || color[fx][fy]==0)
						continue;
					for (int l=k+1;l<4;l++)
					{
						tx=i+wayx[l],ty=j+wayy[l];
						if (tx<1 || tx>n || ty<1 || ty>n || color[tx][ty]==0)
							continue;
						if (color[fx][fy]==color[tx][ty]) continue;
						cost=2;
						if (chess[fx][fy]!=chess[tx][ty]) cost++;
						if (len[color[fx][fy]][color[tx][ty]]>cost)
						{
							len[color[fx][fy]][color[tx][ty]]=cost;
							len[color[tx][ty]][color[fx][fy]]=cost;
						}
					}
				}
			else
				for (int k=0;k<4;k++)
				{
					tx=i+wayx[k],ty=j+wayy[k];
					if (tx<1 || tx>n || ty<1 || ty>n || color[tx][ty]==0)
						continue;
					if (color[tx][ty]==color[i][j]) continue;
					if (len[color[i][j]][color[tx][ty]]>1)
					{
						len[color[i][j]][color[tx][ty]]=1;
						len[color[tx][ty]][color[i][j]]=1;
					}
				}
	
	SPFA();
	
	if (dis[color[n][n]]!=INF) printf("%d\n",dis[color[n][n]]);
		else printf("-1\n");
	
	return 0;
}
