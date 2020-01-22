#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int map[110][110],f[110][110];
bool v[110][110];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int const longint=1000000000;
int n,m;
void print()
{
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++) printf("%d ",f[i][j]);
		printf("\n");
	}	printf("\n");
	return;
}
int work(int x,int y,bool t)
{
	if(x==m&&y==m) return 0;
	if(f[x][y]!=0) return f[x][y];
	v[x][y]=1;
	int ans=longint;
	for(int i=0; i<4; i++)
	{
		int newx=x+dx[i],newy=y+dy[i],f1;
		if(newx<1||newx>m||newy<1||newy>m||v[newx][newy]==1) continue;//越界或访问过 
		if(map[newx][newy]==map[x][y]&&map[newx][newy]!=-1)
		{
			f1=f[x][y]+work(newx,newy,1);
			ans=min(f1,ans);
			continue;
		}//直接走 
		if(t)//有魔法 
		{
			if(map[newx][newy]==-1)
			{
				if(map[x][y]==0) map[newx][newy]=0;
				else map[newx][newy]=1;
				f1=f[x][y]+work(newx,newy,0)+2;
				map[newx][newy]=-1;
			}
			else if(map[newx][newy]!=map[x][y]&&map[newx][newy]!=-1) 
			 f1=min(f[x][y]+work(newx,newy,0)+2,f[x][y]+work(newx,newy,1)+1);//变色或不变
		}
		else//没魔法 
		{
			if(map[newx][newy]==-1) continue;
			else if(map[newx][newy]!=map[x][y]) f1=f[x][y]+work(newx,newy,1)+1;//走
		}
		ans=min(f1,ans);
	}
	f[x][y]=ans;
	v[x][y]=0;
	return f[x][y];
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1; i<=m; i++)
	 for(int j=1; j<=m; j++) map[i][j]=-1;
	for(int i=1; i<=n; i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		map[x][y]=c;
	}
	int ans=work(1,1,1);
	if(ans==longint) printf("-1");
	else printf("%d",ans);
	return 0;
}

