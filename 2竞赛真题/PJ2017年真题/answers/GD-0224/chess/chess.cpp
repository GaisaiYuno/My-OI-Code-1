#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int ma=999999,a[105][105],p[105][105],n,m;
void dfs(int x,int y,int money,int o)
{
	if(x==0||y==0||x>n||y>n) return;
	if(p[x][y]<=money) return;
	p[x][y]=money;
	if(x==n&&y==n)
	{
		ma=min(money,ma);
		return;
	}
	
	if(a[x+1][y]==0&&o==0)	
	{
	a[x+1][y]=a[x][y];
	dfs(x+1,y,money+2,1);
	a[x+1][y]=0;	
	}
	else
	if(a[x+1][y]!=a[x][y]&&a[x+1][y]!=0) dfs(x+1,y,money+1,0);
	else 
	if(a[x+1][y]==a[x][y])dfs(x+1,y,money,0);


	if(a[x-1][y]==0&&o==0)	
	{
		a[x-1][y]=a[x][y];
		dfs(x-1,y,money+2,1);
		a[x-1][y]=0;	
	}
	else
	if(a[x-1][y]!=a[x][y]&&a[x-1][y]!=0) dfs(x-1,y,money+1,0);
	else
	if(a[x-1][y]==a[x][y])dfs(x-1,y,money,0);
	
	
	if(a[x][y+1]==0&&o==0)	
	{
	a[x][y+1]=a[x][y];
	dfs(x,y+1,money+2,1);	
	a[x][y+1]=0;
	}
	else
	if(a[x][y+1]!=a[x][y]&&a[x][y+1]!=0) dfs(x,y+1,money+1,0);
	else 
	if(a[x][y+1]==a[x][y])dfs(x,y+1,money,0);
	
	
	if(a[x][y-1]==0&&o==0)
	{
		a[x][y-1]=a[x][y];
		dfs(x,y-1,money+2,1);
		a[x][y-1]=0;
	}	
	else
	if(a[x][y-1]!=a[x][y]&&a[x][y-1]!=0) dfs(x,y-1,money+1,0);
	else 
	if(a[x][y-1]==a[x][y])dfs(x,y-1,money,0);
	
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int i=1;i<=100;i++)
	for(int j=1;j<=100;j++) p[i][j]=999999;
	int x=0,y=0,k=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>k;
		a[x][y]=k+1;
	}
	dfs(1,1,0,0);
    if(ma!=999999)	cout<<ma;
    else cout<<-1;
	return 0;
}
