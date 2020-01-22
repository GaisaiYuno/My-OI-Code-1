#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int ans=214748364,m,n,a,b,c;
int map[105][105],map1[105][105];
void DFS(int x,int y,int sum,int c)
{
	
	if (x<0||x>m||y<0||y>m||map1[x][y]==1) return;
	if (x==m&&y==m) {ans=min(ans,sum);return;}
	if (map[x][y]!=0&&sum>=map1[x][y]) return;
	map1[x][y]=sum;
	for (int i=0;i<=3;i++)
	  {
	  	int xx1=x+dx[i];
	  	int yy1=y+dy[i];
	  	if (map[xx1][yy1]==0&&map[x][y]==0) continue;else 
		if (map[xx1][yy1]==0&&map[x][y]!=0) DFS(xx1,yy1,sum+2,map[x][y]);else
		if (map[xx1][yy1]!=map[x][y]&&map[x][y]!=0) DFS(xx1,yy1,sum+1,-1);else
		if (map[xx1][yy1]==map[x][y]&&map[x][y]!=0) DFS(xx1,yy1,sum,-1);else
		if (map[x][y]==0&&map[xx1][yy1]!=0) 
		  {
		  	if (c==map[xx1][yy1]) DFS(xx1,yy1,sum,-1);
		  	if (c!=map[xx1][yy1]) DFS(xx1,yy1,sum+1,-1);
		  }
	  }
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	    map1[i][j]=214748364;
	for (int i=1;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	c++;
	  	map[a][b]=c;
	  }
	DFS(1,1,0,-1);
	if (ans==214748364) cout<<-1;else cout<<ans;	
	return 0;
}
