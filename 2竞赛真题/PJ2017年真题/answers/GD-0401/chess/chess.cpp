#include<iostream>
#include<cstdio>
using namespace std;
int map[105][105];
bool visit[105][105];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int m,n,ans=99999999;
void dfs(int x,int y,int money,int t)
{
	
	
	if(x==m&&y==m)
	{
		if(money<ans)ans=money;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		
		if(map[x1][y1]!=3&&visit[x1][y1]==0)
		{
			if(map[x1][y1]==0&&t!=1)
			{
				visit[x][y]=1;map[x1][y1]=map[x][y];
				if(money+2<ans)
				dfs(x1,y1,money+2,1);
				t=0;
				map[x1][y1]=0;
//				visit[x][y]=0;
			}
			else if(map[x1][y1]!=map[x][y]&&map[x1][y1]!=0)
			{
				visit[x][y]=1;
				if(money+1<ans)
				dfs(x1,y1,money+1,0);
//				visit[x][y]=0;
				
			}
			else if(map[x1][y1]!=0)
			{
				visit[x][y]=1;
				if(money<ans)
				dfs(x1,y1,money,0);
//				visit[x][y]=0;
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	int x,y,c;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>c;
		map[x][y]=c+1;
	}
	for(int i=0;i<=m+1;i++)
	{
		map[i][0]=3;
		map[i][m+1]=3;
		map[0][i]=3;
		map[m+1][i]=3;
		visit[i][0]=1;
		visit[i][m+1]=1;
		visit[0][i]=1;
		visit[m+1][i]=1;
	}
	dfs(1,1,0,0);
	if(ans!=99999999)
	cout<<ans;
	else cout<<-1;
	return 0;
}
