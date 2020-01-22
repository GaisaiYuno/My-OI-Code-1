#include<iostream>
#include<cstdio>
using namespace std;
struct data
{
	int x,y,s,sc;
};
data a[1001000],c,d;
int b[110][110],n,m,xx,yy,co,h,t,bj[110][110],ans=2147483647;
const int dx[4]={0,0,-1,1};
	  int dy[4]={-1,1,0,0};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&xx,&yy,&co);
		b[xx][yy]=co+1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			bj[i][j]=2147483647;
	bj[1][1]=0;
	a[1].x=1;
	a[1].y=1;
	a[1].s=0;
	h=1;
	t=1;
	while (h<=t)
	{
		d=a[h++];
		for (int i=0;i<4;i++)
		{
			c.x=d.x+dx[i];
			c.y=d.y+dy[i];
			if (b[d.x][d.y]==0&&b[c.x][c.y]==0) continue;
			if (b[c.x][c.y]==b[d.x][d.y]) c.s=d.s;
			else if (b[c.x][c.y]==0) c.s=d.s+2;
			else if (b[d.x][d.y]!=0||b[d.x][d.y]==0&&d.sc!=b[c.x][c.y]) c.s=d.s+1;
			if (c.x<1||c.x>n||c.y<1||c.y>n||bj[c.x][c.y]<=c.s) continue;
			a[++t]=c;
			bj[c.x][c.y]=c.s;
			a[t].sc=b[d.x][d.y];
			if (c.x==n&&c.y==n&&c.s<ans) ans=c.s;
		}
	}
	if (ans==2147483647) printf("-1"); else printf("%d",ans);
	return 0;
}
