#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,a[1005][1005],f[1005][1005],x,y,c;
struct mon{int x;int y;int m;int p;};
mon sum[100000+5];
const int dx[5]={0,0,1,0,-1};
const int dy[5]={0,1,0,-1,0};
int bfs()
{
	int head=1,tail=1;
	f[1][1]=1;
	sum[head].x=1;sum[head].y=1;sum[head].m=0;sum[head].p=1;
	while (head<=tail)
	{
		mon now=sum[head++];
		for (int i=1;i<=4;i++)
		{
			int ff=0;
			int xx=now.x+dx[i];
			int yy=now.y+dy[i];
			if (xx<1||xx>n||yy<1||yy>n||f[xx][yy]==1) continue;
			if (a[xx][yy]==a[now.x][now.y]) 
			{
				tail++;
				f[xx][yy]=1;
				sum[tail].x=xx;sum[tail].y=yy;
				sum[tail].m=now.m;
				if (now.p==0) ff=1;
				sum[tail].p=1;
			}
			if (a[xx][yy]!=a[now.x][now.y]&&a[xx][yy]!=2)
			{
				tail++;
				f[xx][yy]=1;
				sum[tail].x=xx;sum[tail].y=yy;sum[tail].m=now.m+1;
				if (now.p==0) ff=1;
				sum[tail].p=1;
			}
			if (a[xx][yy]!=a[now.x][now.y]&&a[xx][yy]==2)
			{
			    f[xx][yy]=1;
				if (now.p==0) continue;
				a[xx][yy]=a[now.x][now.y];
				tail++;
				sum[tail].x=xx;sum[tail].y=yy;
				sum[tail].m=now.m+2;sum[tail].p=0;
			}
			if (ff==1) a[now.x][now.y]=2;
			if (xx==n&&yy==n) return sum[tail].m;
		}
	}
	return -1;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++) a[i][j]=2;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c;
	}
	cout<<bfs()<<endl;
	return 0;
}
