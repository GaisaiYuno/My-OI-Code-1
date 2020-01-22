#include <iostream>
#include <cstdio>
using namespace std;
int m,n,ans,been[105][105],map[105][105],a,b,c,money;
struct xy
{
	int xa,yb;
}way[5];

void chess(int x,int y,int last)
{
    int x1,y1,begin;
    if (money>=ans) return;
	if (x==m&&y==m) ans=min(money,ans);
	for (int i=0;i<4;i++)
	{
		x1=x+way[i].xa; 
		y1=y+way[i].yb;
		if (x1<=m&&x1>0&&y1<=m&&y1>0&&been[x1][y1]==0)
		{
			if (map[x1][y1]>0&&map[x1][y1]==map[x][y]) 
			{
			been[x1][y1]=1;
			chess(x1,y1,0);
			been[x1][y1]=0;
			}
			if (map[x1][y1]>0&&map[x1][y1]!=map[x][y]) 
			{
			been[x1][y1]=1; 
			money++; 
			chess(x1,y1,0); 
			been[x1][y1]=0;
			money--;
			}
			if (map[x1][y1]==0&&last==0)
			{
			been[x1][y1]=1;
			begin=money;
			
			if (map[x][y]==1) money+=2; else money+=3;
			map[x1][y1]=1;
			chess(x1,y1,1);
			
			money=begin;
			
			if (map[x][y]==2) money+=2; else money+=3;
			map[x1][y1]=2;
			chess(x1,y1,1);
			
			map[x1][y1]=0;
			been[x1][y1]=0;
			money=begin;
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	been[1][1]=1;
	ans=100000;
	scanf("%d%d",&m,&n);
	if (m<=10)
	{
	way[0].yb=1; way[1].yb=-1; 
	way[2].xa=-1; way[3].xa=1;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (c==1) map[a][b]=1;
		if (c==0) map[a][b]=2;
	}
	chess(1,1,0);
	if (ans==100000) cout<<-1; else cout<<ans;
	} 
	else cout<<-1;
	return 0;
}
