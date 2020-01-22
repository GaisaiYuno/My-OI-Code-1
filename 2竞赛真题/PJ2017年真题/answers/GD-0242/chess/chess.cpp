#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n,color[2100][2100],minn=999999999,bk;
const int dx[2]={0,1};
const int dy[2]={1,0};
void dfs(int x,int y,int s,int k)
{
	if(x==m&&y==m)minn=min(minn,s),bk=1;
	for(int i=0;i<2;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>n||xx<1||yy>n||yy<1)return ;
		if(color[xx][yy]==-1)
		{
			if(k==0)
			{
				k=1;color[xx][yy]=color[x][y];s++;s++;
			}
		}
		else
		{
			if(color[x][y]==1-color[xx][yy])s++;
			k=0;
		}
		dfs(xx,yy,s,k);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(color,-1,sizeof(color));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int xx,yy;scanf("%d%d",&xx,&yy);scanf("%d",&color[xx][yy]);
	}
	dfs(1,1,0,0);
	if(bk==0)minn=-1;
	printf("%d\n",minn);
	return 0;
}
