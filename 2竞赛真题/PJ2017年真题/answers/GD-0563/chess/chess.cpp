#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int qp[110][110];
bool qp1[110][110];
int n,m,ans=20000;
void yx(int x,int y,int now,int coin,bool lq)
{
	qp1[x][y]=1;
	if(x==n&&y==n)
	{
		if(coin<ans) ans=coin;
		qp1[x][y]=0;
		return;
	}
	if(y<n&&qp1[x][y+1]==0)
	{
		if(qp[x][y+1]==0)
		{
			if(lq==0)
				yx(x,y+1,now,coin+2,1);
		}
		else
		{
			if(qp[x][y+1]==now)
				yx(x,y+1,qp[x][y+1],coin,0);
			else
				yx(x,y+1,qp[x][y+1],coin+1,0);
		}
	}
	if(x<n&&qp1[x+1][y]==0)
	{
		if(qp[x+1][y]==0)
		{
			if(lq==0)
				yx(x+1,y,now,coin+2,1);
		}
		else
		{
			if(qp[x+1][y]==now)
				yx(x+1,y,qp[x+1][y],coin,0);
			else
				yx(x+1,y,qp[x+1][y],coin+1,0);
		}
	}
	if(y>1&&qp1[x][y-1]==0)
	{
		if(qp[x][y-1]==0)
		{
			if(lq==0)
				yx(x,y-1,now,coin+2,1);
		}
		else
		{
			if(qp[x][y-1]==now)
				yx(x,y-1,qp[x][y-1],coin,0);
			else
				yx(x,y-1,qp[x][y-1],coin+1,0);
		}
	}
	if(x>1&&qp1[x-1][y]==0)
	{
		if(qp[x-1][y]==0)
		{
			if(lq==0)
				yx(x-1,y,now,coin+2,1);
		}
		else
		{
			if(qp[x-1][y]==now)
				yx(x-1,y,qp[x-1][y],coin,0);
			else
				yx(x-1,y,qp[x-1][y],coin+1,0);
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		qp[x][y]=c+1;
	}
	yx(1,1,qp[1][1],0,0);
	if(ans==20000) ans=-1;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
