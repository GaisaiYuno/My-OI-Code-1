#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,a[101][101];
int temp,temp1,temp2; 
int i;
int ans=99999999;
void dfs(int x,int y,int temp,int col,int sum)
{
	if (x==m&&y==m) {ans=min(ans,sum); return ;}
	if (sum>=ans) return ;
	if (a[x+1][y]!=3)
	{
		if (a[x+1][y]!=0)
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x+1,y,0,a[x+1][y],sum+abs(col-a[x+1][y]));
			a[x][y]=temp1;
		} else 
		if (a[x+1][y]==0&&temp==0) 
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x+1,y,1,col,sum+2);
			a[x][y]=temp1;
		}
		else
		if (a[x+1][y]==0&&temp==1) return; 
	}
	if (a[x][y+1]!=3)
	{
		if (a[x][y+1]!=0)
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x,y+1,0,a[x][y+1],sum+abs(col-a[x][y+1]));
			a[x][y]=temp1;
		} else 
		if (a[x][y+1]==0&&temp==0) 
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x,y+1,1,col,sum+2);
			a[x][y]=temp1;
		}
		else 
		if (a[x+1][y]==0&&temp==1) return;
	}
	if (a[x-1][y]!=3)
	{
		if (a[x-1][y]!=0)
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x-1,y,0,a[x-1][y],sum+abs(col-a[x-1][y]));
			a[x][y]=temp1;
		} else 
		if (a[x-1][y]==0&&temp==0) 
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x-1,y,1,col,sum+2);
			a[x][y]=temp1;
		}
		else
		if (a[x+1][y]==0&&temp==1) return;
	}
	if (a[x][y-1]!=3)
	{
		if (a[x][y-1]!=0)
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x,y-1,0,a[x][y-1],sum+abs(col-a[x][y-1]));
			a[x][y]=temp1;
		} else
		if (a[x][y-1]==0&&temp==0) 
		{
			int temp1=a[x][y];
			a[x][y]=3;
			dfs(x,y-1,1,col,sum+2);
			a[x][y]=temp1;
		}
		else if (a[x+1][y]==0&&temp==1) return; 
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (i=1; i<=m; i++) 
	{
		a[0][i]=3; 
		a[m+1][i]=3;
		a[i][0]=3; 
		a[i][m+1]=3;
	}
	for (i=1; i<=n; i++)
	{
		cin>>temp>>temp1>>temp2; 
		a[temp][temp1]=temp2+1;
	}
	dfs(1,1,0,a[1][1],0);
	if (ans!=99999999) cout<<ans; else cout<<-1; 
	return 0;
}
