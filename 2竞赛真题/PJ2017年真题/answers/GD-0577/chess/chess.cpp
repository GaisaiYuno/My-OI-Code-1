#include<iostream>
#include<cstdio>
using namespace std;
const int wayx[4]={1,0,-1,0},wayy[4]={0,1,0,-1};
int m,n,cost[200][200],a[200][200],x1,y1,c;
bool visit[200][200],magic[200][200];
struct data
{
	int x,y;
}que[100000];
void first()
{
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			cost[i][j]=2147483640;
	cost[1][1]=0;
}
void spfa()
{
	int head=0,tail=1;
	que[head].x=1;que[head].y=1;
	visit[1][1]=true;
	while (head!=tail)
	{
		int nowx=que[head].x,nowy=que[head].y;	
		if (magic[nowx][nowy]&&!a[nowx][nowy]) a[nowx][nowy]=magic[nowx][nowy];
		for (int j=0;j<4;j++)
		{
			int movex=nowx+wayx[j],movey=nowy+wayy[j],nowc=0;
			if (movex<0||movex>m) continue;
			if (movey<0||movey>m) continue;
			if (a[movex][movey]==1&&a[nowx][nowy]==2) nowc+=1;
			if (a[movex][movey]==2&&a[nowx][nowy]==1) nowc+=1;
			if (a[movex][movey]==0) 
			{
				if (magic[nowx][nowy]) nowc=cost[movex][movey]-cost[nowx][nowy]+2;
				else
				{
					nowc+=2;
					magic[movex][movey]=a[nowx][nowy];
				}
			}
			if (cost[nowx][nowy]+nowc<cost[movex][movey])
			{
				if (!visit[movex][movey])
				{
					que[tail].x=movex;que[tail].y=movey;
					tail++;
					visit[movex][movey]=true;
				}
				cost[movex][movey]=cost[nowx][nowy]+nowc;
			}
			else if (nowc==2) magic[movex][movey]=0;
		}
		visit[nowx][nowy]=false;
		if (magic[nowx][nowy]) a[nowx][nowy]=0;
		magic[nowx][nowy]=0;
		head++;	
	}
}
int main()
{
	//freopen("chess.in","r",stdin);
	//freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x1,&y1,&c);
		a[x1][y1]=c+1;
	}
	first();
	spfa();
	if (cost[m][m]==2147483640) cout<<-1;
	else cout<<cost[m][m];
	return 0;
}
