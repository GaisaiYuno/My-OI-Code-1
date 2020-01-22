#include <iostream>
#include <cstdio>
using namespace std;
int n,ans=10000000;
int w[110][110],jl[110][110],pd[110][110];
int xx[]={-1,1,0,0};
int yy[]={0,0,-1,1};
void dfs(int x,int y,int t,int used)
{
	if(t>ans) return;
	if(x==n&&y==n)
	{
		if(t<ans) ans=t;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int x1=x+xx[i];
		int y1=y+yy[i];
		if(x1<1||y1<1||x1>n||y1>n||jl[x1][y1]) continue;
		jl[x1][y1]=1;
		if(w[x1][y1]==-1&&used==0) 
		{
			pd[x1][y1]=1;
			w[x1][y1]=1;
			if(w[x][y]==w[x1][y1]) dfs(x1,y1,t+2,1);
			else dfs(x1,y1,t+3,1);
			w[x1][y1]=0;
			if(w[x][y]==w[x1][y1]) dfs(x1,y1,t+2,1);
			else dfs(x1,y1,t+3,1);
			w[x1][y1]=-1;
			pd[x1][y1]=0;
		}
		if(w[x1][y1]!=-1) 
		{
			used=0;
			if(w[x][y]==w[x1][y1]) dfs(x1,y1,t,used);
			else dfs(x1,y1,t+1,used);
			if(pd[x][y]==1) used=1;
		}
		jl[x1][y1]=0;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,a,b,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		w[a][b]=c;
	}
	dfs(1,1,0,0);
	if(ans==10000000) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
