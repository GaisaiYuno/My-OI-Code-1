#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#define INFF INT_MAX-10
using namespace std;

int color[101][101];
int dis[101][101];
int totge,totcolor;

void dfs(int x,int y,bool magicable)
{
	int willx,willy;
	
	willx=x-1;willy=y;
	if(willx>=1)
	{
		if(color[willx][willy]!=-1)
		{
			if(dis[willx][willy]>dis[x][y]+(color[x][y]^color[willx][willy]))
			{
				dis[willx][willy]=dis[x][y]+(color[x][y]^color[willx][willy]);
				dfs(willx,willy,1);
			}
		}
		else
		{
			if(magicable!=0)
			{
				color[willx][willy]=color[x][y];
				dis[willx][willy]=dis[x][y]+2;
				dfs(willx,willy,0);
				color[willx][willy]=-1;
			}
		}
	}
	willx=x+1;willy=y;
	if(willx<=totge)
	{
		if(color[willx][willy]!=-1)
		{
			if(dis[willx][willy]>dis[x][y]+(color[x][y]^color[willx][willy]))
			{
				dis[willx][willy]=dis[x][y]+(color[x][y]^color[willx][willy]);
				dfs(willx,willy,1);
			}
		}
		else
		{
			if(magicable!=0)
			{
				color[willx][willy]=color[x][y];
				dis[willx][willy]=dis[x][y]+2;
				dfs(willx,willy,0);
				color[willx][willy]=-1;
			}
		}
	}
	
	willx=x;willy=y+1;
	if(willy<=totge)
	{
	//	cout<<"test "<<willx<<" "<<willy<<" "<<dis[x][y]<<endl;
		if(color[willx][willy]!=-1)
		{
			if(dis[willx][willy]>dis[x][y]+(color[x][y]^color[willx][willy]))
			{
				dis[willx][willy]=dis[x][y]+(color[x][y]^color[willx][willy]);
				dfs(willx,willy,1);
			}
		}
		else
		{
			if(magicable!=0)
			{
				color[willx][willy]=color[x][y];
				dis[willx][willy]=dis[x][y]+2;
				dfs(willx,willy,0);
				color[willx][willy]=-1;
			}
		}
	}
	willx=x;willy=y-1;
	if(willy>=1)
	{
		if(color[willx][willy]!=-1)
		{
			if(dis[willx][willy]>dis[x][y]+(color[x][y]^color[willx][willy]))
			{
				dis[willx][willy]=dis[x][y]+(color[x][y]^color[willx][willy]);
				dfs(willx,willy,1);
			}
		}
		else
		{
			if(magicable!=0)
			{
				color[willx][willy]=color[x][y];
				dis[willx][willy]=dis[x][y]+2;
				dfs(willx,willy,0);
				color[willx][willy]=-1;
			}
		}
	}
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int x,y,t;
	int i,j;
	
	scanf("%d%d",&totge,&totcolor);
	
	for(i=1;i<=totge;++i)
	{
		for(j=1;j<=totge;++j)
		{
			color[i][j]=-1;
			dis[i][j]=INFF;
		}	
	}
	dis[1][1]=0;
	
	for(i=1;i<=totcolor;++i)
	{
		scanf("%d%d%d",&x,&y,&t);
		color[x][y]=t;
	}
	dfs(1,1,1);
	if(dis[totge][totge]!=INFF) printf("%d\n",dis[totge][totge]);
	else printf("-1\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
