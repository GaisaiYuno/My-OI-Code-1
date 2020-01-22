#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int m,n,mp[105][105],f[105][105],f2[105][105];
bool check(int x,int y)
{
	if(x>=1&&y>=1&&x<=m&&y<=m)return 1;
	return 0;
}
int dfs(int wx,int wy,int nx,int ny,int w)
{
//	printf("%d",w);
	//if(wx==nx)
	//if(wx==4&&wy==5&&nx==5&&ny==5)
	//printf("%d\n",f[m][m]);
	if(abs(wx-nx)==2||abs(wy-ny)==2||(abs(wx-nx)==1&&abs(wy-ny)==1))
	{
		if(mp[wx][wy]==mp[nx][ny])
		{
			w+=2;
		}
		else 
		{
			w+=3;
		}
	}
	else if(mp[wx][wy]!=mp[nx][ny])++w;
	if(f[nx][ny]<=w)return 0;
	f2[nx][ny]=1;
	f[nx][ny]=w;
	if(check(nx+1,ny)&&mp[nx+1][ny]!=-1)dfs(nx,ny,nx+1,ny,w);
	if(check(nx-1,ny)&&mp[nx-1][ny]!=-1)dfs(nx,ny,nx-1,ny,w);
	if(check(nx,ny+1)&&mp[nx][ny+1]!=-1)dfs(nx,ny,nx,ny+1,w);
	if(check(nx,ny-1)&&mp[nx][ny-1]!=-1)dfs(nx,ny,nx,ny-1,w);
	
	if(check(nx+1,ny)&&mp[nx+1][ny]==-1)
	{
		int x=nx+1;
		int y=ny;
		if(check(x+1,y)&&mp[x+1][y]!=-1)dfs(nx,ny,x+1,y,w);
		if(check(x,y+1)&&mp[x][y+1]!=-1)dfs(nx,ny,x,y+1,w);
		if(check(x,y-1)&&mp[x][y-1]!=-1)dfs(nx,ny,x,y-1,w);
	}
	
	if(check(nx-1,ny)&&mp[nx-1][ny]==-1)
	{
		int x=nx-1;
		int y=ny;
		if(check(x-1,y)&&mp[x-1][y]!=-1)dfs(nx,ny,x-1,y,w);
		if(check(x,y+1)&&mp[x][y+1]!=-1)dfs(nx,ny,x,y+1,w);
		if(check(x,y-1)&&mp[x][y-1]!=-1)dfs(nx,ny,x,y-1,w);
	}
	
	if(check(nx,ny+1)&&mp[nx][ny+1]==-1)
	{
		int x=nx;
		int y=ny+1;
		if(check(x+1,y)&&mp[x+1][y]!=-1)dfs(nx,ny,x+1,y,w);
		if(check(x-1,y)&&mp[x-1][y]!=-1)dfs(nx,ny,x-1,y,w);
		if(check(x,y+1)&&mp[x][y+1]!=-1)dfs(nx,ny,x,y+1,w);
		//if(check(x,y-1)&&mp[x][y-1]!=-1))dfs(nx,ny,x,y-1,w);
	}
	if(check(nx,ny-1)&&mp[nx][ny-1]==-1)
	{
		int x=nx;
		int y=ny-1;
		if(check(x+1,y)&&mp[x+1][y]!=-1)dfs(nx,ny,x+1,y,w);
		if(check(x-1,y)&&mp[x-1][y]!=-1)dfs(nx,ny,x-1,y,w);
		if(check(x,y-1)&&mp[x][y-1]!=-1)dfs(nx,ny,x,y-1,w);
		//if(check(x,y+1)&&mp[x][y-1]!=-1))dfs(nx,ny,x,y-1,w);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(mp,-1,sizeof(mp));
	memset(f,0x7f,sizeof(f));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		mp[x][y]=w;
	}
	dfs(1,1,1,1,0);
	if(!f2[m][m])
	{
		if(f2[m-1][m]||f2[m][m-1])printf("%d",min(f[m-1][m],f[m][m-1])+2);else printf("-1");
	}else printf("%d",f[m][m]);
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0

5 15
1 1 1
2 1 1
3 1 1
4 1 1
5 1 1
5 2 1
5 3 1
4 3 1
3 3 1
2 3 1
1 4 1
2 5 2
3 5 1
4 5 1
5 5 1
*/
