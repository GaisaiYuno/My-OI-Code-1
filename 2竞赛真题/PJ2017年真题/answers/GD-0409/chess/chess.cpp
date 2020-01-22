#include<bits/stdc++.h>
using namespace std;
int f[110][110][3];//f[i][j][1] red   f[i][j][2] yellow
int n,m,i,j,k,a[110][110],x,y,l=1,r=1;
int fx[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct hh
{
	int x,y,sum,col;
}q[15000000];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(f,127,sizeof(f));
	scanf("%d %d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		scanf("%d",&a[x][y]);
		a[x][y]++;
	}
	f[1][1][a[1][1]]=0;q[1]={1,1,0,a[1][1]};
	while (l<=r)
	{
		int x=q[l].x,y=q[l].y,sum=q[l].sum,col=q[l].col;
		for (i=0;i<4;i++)
		{
			int xx=x+fx[i][0],yy=y+fx[i][1];
			if (!(xx>0&&yy>0&&xx<=n&&yy<=n)) continue;
			if (!a[xx][yy]&&!a[x][y]) continue;
			if (a[xx][yy])
			{
				int now=sum+(col!=a[xx][yy]);
				if (now<f[xx][yy][a[xx][yy]])
				{
					f[xx][yy][a[xx][yy]]=now;
					q[++r]={xx,yy,now,a[xx][yy]};
				}
			}
			else
			{
				int now1=sum+2,now2=sum+3;
				if (now1<f[xx][yy][col])
				{
					f[xx][yy][a[x][y]]=now1;
					q[++r]={xx,yy,now1,a[x][y]};
				}
				int c=(col==1?2:1);
				if (now2<f[xx][yy][c])
				{
					f[xx][yy][c]=now2;
					q[++r]={xx,yy,now2,c};
				}
			}
		}
		l++;
	}
	int ans=min(f[n][n][1],f[n][n][2]);
	cout<<(ans==2139062143?-1:ans);
}
