#include<iostream>
#include<cstdio>
using namespace std;
int m,n,map[101][101],s[101][101],it=0;
long long money=0,tip=100000001;
int dp[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void check(int g,int h,int q,int w)
{
	if(map[g][h]==-1&&map[q][w]==0){money+=2;return;}
	if(map[g][h]==-1&&map[q][w]==1){money+=2;return;}
	if(map[g][h]==1&&map[q][w]==0){money+=1;return;}
	if(map[g][h]==0&&map[q][w]==1){money+=1;return;}
	if(map[g][h]==1&&map[q][w]==-1){money+=1;return;}
	if(map[g][h]==0&&map[q][w]==-1){money+=1;return;}
	if(map[g][h]==1&&map[q][w]==1)return;
	if(map[g][h]==0&&map[q][w]==0)return;
}
void dfs(int x,int y)
{
	if(x==m&&y==m&&money<tip)
		{tip=money;it++;return;}
	for(int i=0;i<4;i++)
	{
		int a=x+dp[i][0];
		int b=y+dp[i][1];
		if(a>=1&&a<=m&&b>=1&&b<=m&&s[a][b]==0)
		{
			s[a][b]=1;
			check(a,b,x,y);
			cout<<money<<' '<<x<<' '<<y<<' '<<map[x][y]<<' '<<a<<' '<<b<<' '<<map[a][b]<<endl;
			if(map[a][b]==-1&&(map[x][y]==0||map[x][y]==1))
			{
				dfs(a,b);
			}
			if((map[a][b]==0&&map[x][y]==1)||(map[a][b]==1&&map[x][y]==0)||(map[a][b]==1&&map[x][y]==-1)||(map[a][b]==0&&map[x][y]==-1))
			{
				dfs(a,b);
			}
			if((map[a][b]==1&&map[x][y]==1)||(map[a][b]==0&&map[x][y]==0))
			{
				dfs(a,b);
			}
			s[a][b]=0;	
		}
	}
}
int main()
{
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	cin>>m>>n;
	s[1][1]=1;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			map[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		map[x][y]=c;
	}	
	dfs(1,1);
	if(it==0)cout<<"-1";
	else cout<<tip;
	return 0;
}
