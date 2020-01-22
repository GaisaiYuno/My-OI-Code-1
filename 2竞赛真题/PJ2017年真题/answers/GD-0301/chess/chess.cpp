#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
struct data
{
	int x,y,t;
};
data opens[100005];
int map[105][105],a[105][105],x,y,c,n,m,f;
void ks(int x,int y)
{
	int head=1,tail=1;
	opens[1].x=x;
	opens[1].y=y;
	opens[1].t=0;
	map[x][y]=1;
	while (head<=tail)
	{
		for (int i=0;i<4;i++)
		{
			int xx=opens[head].x+dx[i];
			int yy=opens[head].y+dy[i];
			int tt=opens[head].t;
			
			if (xx<1||yy<1||xx>n||yy>n||map[xx][yy]==1) continue;
			if (a[xx][yy]==0&&a[opens[head].x][opens[head].y]==0) continue;
			if (a[xx][yy]==0&&(a[opens[head].x][opens[head].y]==2||a[opens[head].x][opens[head].y]==1)) tt+=2; else
			if (a[xx][yy]==1&&a[opens[head].x][opens[head].y]==2) tt+=1; else 
			if (a[xx][yy]==2&&a[opens[head].x][opens[head].y]==1) tt+=1;	
			if (xx==n&&yy==n)
			{
				cout<<tt;
				exit(0);
			}
			tail++;
			opens[tail].x=xx;
			opens[tail].y=yy;
			opens[tail].t=tt;
			map[xx][yy]=1;
		}
		head++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		if (c==1) a[x][y]=1; else 
		if (c==0) a[x][y]=2;
	}
	ks(1,1);
	cout<<-1;
}
