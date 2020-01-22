#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
int n,m,k,kk,kkk,a[102][102],b[102][102]={0},Min=1000005;
bool op[102][102]={false};
void shousuo(int x,int y,int mon)
{
	if (x==0) return ;
	if (y==0) return ;
	if (x==n+1) return ;
	if (y==n+1) return ;
	if (b[x][y]>mon) b[x][y]=mon;
	if (b[x][y]==0) b[x][y]=mon;
	if (x==n&&y==n) return ;
	op[x][y]=true;
	if (b[n][n]!=0 && b[n][n]<Min) Min=b[n][n];
	if (op[x+1][y]!=true)
	{
		if (a[x][y]==0 && a[x+1][y]!=0) shousuo(x+1,y,mon);else	
		if (a[x+1][y]==0 && a[x][y]!=0) shousuo(x+1,y,mon+2);else
		if (a[x+1][y]!=0 && a[x+1][y]!=a[x][y]) shousuo(x+1,y,mon+1);else
		if (a[x+1][y]==a[x][y] && a[x+1][y]!=0) shousuo(x+1,y,mon);
		op[x+1][y]=false;
	}
	if (op[x-1][y]!=true)
	{
		if (a[x][y]==0 && a[x-1][y]!=0) shousuo(x-1,y,mon);else
		if (a[x-1][y]==0 && a[x][y]!=0) shousuo(x-1,y,mon+2);else
		if (a[x-1][y]!=0 && a[x-1][y]!=a[x][y]) shousuo(x-1,y,mon+1);else
		if (a[x-1][y]==a[x][y] && a[x-1][y]!=0) shousuo(x-1,y,mon);
		op[x-1][y]=false;
	}
	if (op[x][y+1]!=true)
	{
		if (a[x][y]==0 && a[x][y+1]!=0) shousuo(x,y+1,mon);else
		if (a[x][y+1]==0 && a[x][y]!=0) shousuo(x,y+1,mon+2);else
		if (a[x][y+1]!=0 && a[x][y+1]!=a[x][y]) shousuo(x,y+1,mon+1);else
		if (a[x][y+1]==a[x][y] && a[x][y+1]!=0) shousuo(x,y+1,mon);
		op[x][y+1]=false;
	}
	if (op[x][y-1]!=true)
	{
		if (a[x][y]==0 && a[x][y-1]!=0) shousuo(x,y-1,mon);else
		if (a[x][y-1]==0 && a[x][y]!=0) shousuo(x,y-1,mon+2);else
		if (a[x][y-1]!=0 && a[x][y-1]!=a[x][y]) shousuo(x,y-1,mon+1);else
		if (a[x][y-1]==a[x][y] && a[x][y-1]!=0) shousuo(x,y-1,mon);
		op[x][y-1]=false;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<m;a[k][kk]=kkk+1,i++)
	cin >> k >> kk >> kkk;
	if (a[n-1][n-1]==0&&a[n-2][n]==0&&a[n][n-2]==0&&a[n-1][n]==0&&a[n][n-1]==0) {cout << "-1";return 0;}
	shousuo(1,1,0);
for (int i=1;i<=n-1;i++)
for (int j=1;j<=n-1;j++)
if (a[i][j]!=a[i+1][j+1]&&a[i+1][j]==0&&a[i][j+1]==0&&a[i][j]!=0&&b[i][j]>0&&b[i-1][j-1]>0) Min++;
for (int i=2;i<=n;i++)
for (int j=2;j<=n-1;j++)
if (a[i][j]!=a[i-1][j-1]&&a[i-1][j]==0&&a[i][j-1]==0&&a[i][j]!=0&&b[i][j]>0&&b[i-1][j-1]>0) Min++;
if (Min<1000005)cout << Min;else
	if (a[n-1][n-1]==0&&a[n-2][n]==0&&a[n][n-2]==0&&a[n-1][n]==0&&a[n][n-1]==0) cout << "-1";else cout << "0";
	return 0;
}
