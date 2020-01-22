#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int book[1000][1000];
bool top=false;
int f[1005][1005],jl[1005][1005],a,b,c,n,m;
int ans,sheep=2e9,met;
void push(int i,int j,int v)
{
	int tem=0; 
	book[i][j]=1;
	if (f[i][j]==0) {tem=2; jl[i][j]=0;f[i][j]=v;} else
	if (f[i][j]!=v) {tem=1; jl[i][j]=f[i][j];} 
	else jl[i][j]=v;
	ans+=tem;
	return;
}
void out(int i,int j,int v)
{
	int tem=0; 
	f[i][j]=jl[i][j];
	if (f[i][j]==0) {tem=2; } else
	if (f[i][j]!=v) tem=1;
	book[i][j]=0;
	ans=ans-tem;
	return;
}
void dfs(int x,int y)
{
	if (met==2) return;
	if (x==m&&y==m)
	{
		top=true;
		sheep=min(ans,sheep);
		return;
	}
	if (x<m&&book[x+1][y]==0)
	{
			if (f[x+1][y]==0) met++;
			push(x+1,y,f[x][y]);  
			dfs(x+1,y);
			out(x+1,y,f[x][y]);
			if (f[x+1][y]==0) met--;
	}         
	if (x>1&&book[x-1][y]==0)
	{
		if (f[x-1][y]==0) met++;
			push(x-1,y,f[x][y]); 
			dfs(x-1,y);
			out(x-1,y,f[x][y]); 
		if (f[x-1][y]==0) met--;
	}
	if (y<m&&book[x][y+1]==0)
	{
		if (f[x][y+1]==0) met++;
			push(x,y+1,f[x][y]);
			dfs(x,y+1);
			out(x,y+1,f[x][y]); 
			if (f[x][y+1]==0) met--;
	}
	if (y>1&&book[x][y-1]==0)
	{
if (f[x][y-1]==0) met++;
			push(x,y-1,f[x][y]);
			dfs(x,y-1);
			out(x,y-1,f[x][y]); 
			if (f[x][y-1]==0) met--;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a>>b>>c;
		f[a][b]=c;
	}
	book[1][1]=1;
	jl[1][1]=f[1][1];
	dfs(1,1);
	if (top==0) cout<<-1; else cout<<sheep;
	return 0;
}
