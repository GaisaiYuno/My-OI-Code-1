#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int m,n;
int vis[105][105];
int ans[105][105];
bool hh[105][105];
int x,y,color;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int xx,yy;
int p=0;
bool check(int x,int y)
{
	if (x>=1&&x<=m&&y>=1&&y<=m&&vis[x][y]!=0) return true;
	return false;
}
void prepares()
{
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	    if (vis[i][j]!=0&&hh[i][j]) {
	      for (int k=1;k<=4;k++)
	        if (!hh[i+dx[k]][j+dy[k]])
			vis[i+dx[k]][j+dy[k]]=3;
	    }
}
void bfs(int x,int y)
{
	int x2,y2,outx,outy;
	queue<int>qx; queue<int>qy;
	qx.push(x); qy.push(y);
	vis[x][y]=0;
	while (!qx.empty()||!qy.empty()) {
		x2=qx.front(); y2=qy.front();
		outx=x2; outy=y2;
	  for (int i=1;i<=4;i++) {
	  	x2=x2+dx[i]; y2=y2+dy[i];
	  	if (check(x2,y2)) {
	  		if (vis[x2][y2]!=vis[outx][outy])
			  ans[x2][y2]=ans[outx][outy]+1;
			  vis[x2][y2]=0;
	  		if (x2==m&&y2==m) return; 
	  	  qx.push(x2); qy.push(y2);
	  	}
	  }
	  qx.pop(); qy.pop();
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	if (m==1) {
		printf("%d",0);
		return 0;
	}
	memset(hh,false,sizeof(hh));
	for (int i=1;i<=n;i++) {
	  scanf("%d%d%d",&x,&y,&color);
	  vis[x][y]=color+1;
	  hh[x][y]=true;
	}
	prepares();
	bfs(1,1);
	if (ans[m][m]==0) printf("%d",-1);
	else printf("%d",ans[m][m]);
	fclose(stdin); fclose(stdout);
	return 0;
}

