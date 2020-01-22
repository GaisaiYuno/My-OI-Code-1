#include <iostream>
#include <cstdio>
using namespace std;
int map[150][150],m,vis[150][150],ans[150][150],mid;
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
bool change[150][150],yes;
void checkk(int x,int y,int minn)
{
	int i;
	if (x==m && y==m) {ans[m][m]=minn;yes=true;return;}
	vis[x][y]=true;
	for (i=0;i<4;i++)
	{
		int nx=x+xx[i],ny=y+yy[i],nsum=0;
		if (!nx || nx>m || !ny || ny>m || vis[nx][ny]) {continue;}
		if (!map[nx][ny])
		{
			if (!change[x][y])
			{
				change[nx][ny]=true;
				nsum=2;
				map[nx][ny]=map[x][y];
			}
			else {continue;}
		}
		else if (map[nx][ny]!=map[x][y]) {nsum=1;}
		if (minn+nsum>mid)
		{
			if (change[nx][ny]) {map[nx][ny]=0;change[nx][ny]=false;}
			continue;
		}
		checkk(nx,ny,minn+nsum);
		if (change[nx][ny]) {map[nx][ny]=0;change[nx][ny]=false;}
	}
	vis[x][y]=false;
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,n,px,py,col,l,r;
	bool f=false;
	cin>>m>>n;
	l=0;
	r=m*2+1;
	for(i=1;i<=n;i++)
	{
		cin>>px>>py>>col;
		map[px][py]=col+1;
	}
	while (r>l)
	{
		yes=false;
		for (i=1;i<=m;i++)
		{
			for (j=1;j<=m;j++) {ans[i][j]=2147483647;change[i][j]=0;}
		}
		mid=(l+r)/2;
		checkk(1,1,0);
		if (ans[m][m]==2147483647) {yes=false;}
		if (yes) {r=mid;f=true;}
		else {l=mid+1;}
	}
	if (!f) {cout<<-1;}
	else {cout<<r;}
	return 0;
}
