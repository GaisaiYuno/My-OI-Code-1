#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,map[105][105],l,p;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool used=1,lyq=1;
bool yz[105][105];
int ans=0x3f3f3f3f;
void dfs(int x,int y,int num){
	if(num>ans) return;
	if(x==n&&y==n)
	{
		lyq=0;
		ans=min(ans,num);
		return;
	}
	yz[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx==0||nx>m||ny==0||ny>m) continue;
		if(map[x][y]==map[nx][ny]&&!(yz[nx][ny]))
		{
			used=1;
			yz[nx][ny]=1;
			dfs(nx,ny,num);
			yz[nx][ny]=0;
		}
		else if(map[x][y]!=map[nx][ny]&&map[x][y]!=-1&&map[nx][ny]!=-1&&!(yz[nx][ny]))
		{
			used=1;
			yz[nx][ny]=1;
			dfs(nx,ny,num+1);
			yz[nx][ny]=0;
		}
		else if(map[nx][ny]==-1&&used&&!(yz[nx][ny]))
		{
			used=0;
			map[nx][ny]=map[x][y];
			yz[nx][ny]=1;
			dfs(nx,ny,num+2);
			used=1;
			map[nx][ny]=-1;
			yz[nx][ny]=0;
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	{
		map[i][j]=-1;
		yz[i][j]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>l>>p;
		cin>>map[l][p];
	}
	dfs(1,1,0);
	if(lyq) ans=-1;
	cout<<ans;
	return 0;
}
