#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,a[110][110],cx,cy,c,mg[110][110],k1[]={1,-1,0,0},k2[]={0,0,1,-1};
bool p[110][110];
void dfs(int x,int y,int g,bool t)
{
	if(x<1||y<1||x>n||y>n||p[x][y]||g>=mg[x][y]) return;
	p[x][y]=1;
	mg[x][y]=g;
	if(t)
	{
		for(int i=0;i<4;i++)
		{
			int xx=x+k1[i];
			int yy=y+k2[i];
			if(a[xx][yy]==0) continue;
			else if(a[xx][yy]!=a[x][y]) dfs(xx,yy,g+1,0);
				 else dfs(xx,yy,g,0);
		}
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			int xx=x+k1[i];
			int yy=y+k2[i];
			if(a[xx][yy]==0)
			{
				a[xx][yy]=a[x][y];
				dfs(xx,yy,g+2,1);
				a[xx][yy]=0;
			}
			else if(a[xx][yy]!=a[x][y]) dfs(xx,yy,g+1,0);
				 else dfs(xx,yy,g,0);
		}
	}
	p[x][y]=0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(mg,24,sizeof(mg));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>cx>>cy>>c;
		a[cx][cy]=c+1;
	}
	if(a[1][1]==0) dfs(1,1,0,1);
	else dfs(1,1,0,0);
	if(mg[n][n]>404000000) cout<<-1<<endl;
	else cout<<mg[n][n]<<endl;
	return 0;
}
