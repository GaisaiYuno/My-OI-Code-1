#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
	using namespace std;
	const int INF=2147483647;
	bool book[105][105],magic[105][105];
	int m=0,n=0,ans=INF,map[105][105],H[5]={0,1,-1,0,0},Z[5]={0,0,0,-1,1};
void dfs(int x,int y,int z)
{
	if(x>m||x<1||y>m||y<1||map[x][y]==0||z>=ans) return;
	if(x==m&&y==m)
	{
		ans=z;
		return;
	}
	bool Flag=false;
	int ys=map[x][y];	
	if(magic[x][y]==true)
	{
		Flag=true;
		map[x][y]=0;
		magic[x][y]=false;
	}
	for(int i=1;i<=4;i++)
		if(book[x+H[i]][y+Z[i]]==false)
		{
			book[x+H[i]][y+Z[i]]=true;
			if(ys!=map[x+H[i]][y+Z[i]]) dfs(x+H[i],y+Z[i],z+1);
				        		   else dfs(x+H[i],y+Z[i],z);
			if(map[x+H[i]][y+Z[i]]==0&&Flag==false)
			{
				magic[x+H[i]][y+Z[i]]=true;
				map[x+H[i]][y+Z[i]]=map[x][y];
			    dfs(x+H[i],y+Z[i],z+2);
			    map[x+H[i]][y+Z[i]]=0;
			    magic[x+H[i]][y+Z[i]]=false;
			}
			book[x+H[i]][y+Z[i]]=false;
		}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int x=0,y=0,c=0;
		cin>>x>>y>>c;
		map[x][y]=c+1;
	}
	book[1][1]=true;
	dfs(1,1,0);
	if(ans==INF) cout<<-1;
			else cout<<ans;
	return 0;
}
