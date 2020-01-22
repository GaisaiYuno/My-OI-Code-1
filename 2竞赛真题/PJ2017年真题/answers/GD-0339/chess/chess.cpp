#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

int m,n,xx,yy,c,ans=2147483647;
int mapp[101][101];
bool visit[101][101];
int xi[12]={0,1,0,-1,1,1,-1,-1,0,0,2,-2},yi[12]={1,0,-1,0,-1,1,-1,1,2,-2,0,0};

void dfs(int x,int y,int cost,bool cmagic)
{
	visit[x][y]=true;
//	printf("%d %d %d %d\n",x,y,cost,cmagic);
	if(x==m && y==m) 
	{
		ans=min(ans,cost);
	}
	for(int i=0;i<4;i++)
	{
		if(x+xi[i]>=1 && x+xi[i]<=m && y+yi[i]>=1 && y+yi[i]<=m && visit[x+xi[i]][y+yi[i]]==false)
		{
			if(mapp[x+xi[i]][y+yi[i]]==mapp[x][y]) 
			{
				dfs(x+xi[i],y+yi[i],cost,true);
			}
			if(mapp[x+xi[i]][y+yi[i]]==-mapp[x][y])
			{
				dfs(x+xi[i],y+yi[i],cost+1,true);
			}
			if(mapp[x+xi[i]][y+yi[i]]==0 && mapp[x][y]==1 && cmagic==true)			
			{
				mapp[x+xi[i]][y+yi[i]]=1;
				dfs(x+xi[i],y+yi[i],cost+2,false);
				mapp[x+xi[i]][y+yi[i]]=-1;
				dfs(x+xi[i],y+yi[i],cost+3,false);
				cmagic=true;
			}
			if(mapp[x+xi[i]][y+yi[i]]==0 && mapp[x][y]==-1 && cmagic==true)
			{
				mapp[x+xi[i]][y+yi[i]]=1;
				dfs(x+xi[i],y+yi[i],cost+3,false);
				mapp[x+xi[i]][y+yi[i]]=-1;
				dfs(x+xi[i],y+yi[i],cost+2,false);
				cmagic=true;
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&xx,&yy,&c);
		if(c==0) c=-1;
		mapp[xx][yy]=c;
	}
	dfs(1,1,0,true);
	if(ans==2147483647) printf("-1");
	else printf("%d",ans);
}
/*
5 15
1 1 0
1 3 1
2 3 1
3 3 1
3 2 1
3 1 1
1 5 0
2 5 0
3 5 0
4 5 0
5 5 1
5 4 0
5 3 0
5 2 0
5 1 0
*/
