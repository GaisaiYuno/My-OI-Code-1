#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;
struct data{int x,y,thing;}op[100000];
int costt[110][110][3];
bool st[110][110][3];
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int l,r,ll,rr,x,y,xx,yy,n,m;
int map[110][110],cost[110][110],coss,z;
bool tt[110][110],t[110][110];
void bfs()
{
	op[1].x=1;op[1].y=1;l=r=1;tt[1][1]=true;
	while (l<=r)
	{
		ll=l%10000;
		x=op[ll].x;y=op[ll].y;
		for (int i=0;i<4;i++)
		{
			xx=x+dx[i];yy=y+dy[i];
			if (xx>n||yy>n||xx<1||yy<1||!map[x][y]&&!map[xx][yy])continue;
			if (map[x][y]&&map[xx][yy])
			{
				coss=cost[x][y]+(bool)(map[x][y]!=map[xx][yy]);
				if (t[xx][yy]||!t[xx][yy]&&cost[xx][yy]>coss)
				{
					cost[xx][yy]=coss;t[xx][yy]=false;
					if (!tt[xx][yy])
					{r++;tt[xx][yy]=true;rr=r%10000;op[rr].x=xx;op[rr].y=yy;}
				}
				continue;
			}
			if (map[x][y])
			{
				coss=cost[x][y]+2;
				if (t[xx][yy]||!t[xx][yy]&&costt[xx][yy][map[x][y]]>coss)
				{
					costt[xx][yy][map[x][y]]=coss;t[xx][yy]=false;
					if (!st[xx][yy][map[x][y]])
					{
						r++;st[xx][yy][map[x][y]]=true;rr=r%10000;
						op[rr].x=xx;op[rr].y=yy;op[rr].thing=map[x][y];
					}
				}
			}
			if (map[xx][yy])
			{
				coss=costt[x][y][op[ll].thing]+(bool)(op[ll].thing!=map[xx][yy]);
				if (t[xx][yy]||!t[xx][yy]&&cost[xx][yy]>coss)
				{
					cost[xx][yy]=coss;t[xx][yy]=false;
					if (!tt[xx][yy])
					{r++;tt[xx][yy]=true;rr=r%10000;op[rr].x=xx;op[rr].y=yy;}
				}
			}
		}
		if (map[x][y])tt[x][y]=false;else st[x][y][op[ll].thing]=false;
		l++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
	cin>>n>>m;for (int i=1;i<=m;i++){scanf("%d%d%d",&x,&y,&z);z++;map[x][y]=z;}
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)
	{
		t[i][j]=true;
		if (map[i][j]){cost[i][j]=1000000;tt[i][j]=false;}
		else 
		{
			costt[i][j][1]=1000000;st[i][j][1]=false;
			costt[i][j][2]=1000000;st[i][j][2]=false;
		}
	}
	cost[1][1]=0;t[1][1]=false;bfs();
	if (t[n][n])printf("-1");else 
		if (map[n][n])cout<<cost[n][n];
			else cout<<min(costt[n][n][1],costt[n][n][2]);
	return 0;
}
