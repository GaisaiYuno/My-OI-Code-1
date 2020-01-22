#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int x[5]={0,0,1,-1};
int y[5]={1,-1,0,0};
int m,xxx,yyy,l,r,z,n,a,f[105][105],ff[105][105];
void dfs(int xx,int yy,int p)
{
	if(xx<1||yy<1||xx>m||yy>m) return;
	for(int i=0;i<4;i++)
	{
		xxx=xx+x[i];
		yyy=yy+y[i];
		a=ff[xxx][yyy];
		if(xxx>0&&xxx<=m&&yyy<=m&&yyy>0&&(f[xx][yy]>0||f[xxx][yyy]>0))
		{
			ff[xxx][yyy]=ff[xx][yy];
			if(p!=f[xxx][yyy])
			{
				ff[xxx][yyy]++;
			}
			if(f[xxx][yyy]==0) ff[xxx][yyy]++;
		} 
		if((a>ff[xxx][yyy]||a==-1)&&ff[xxx][yyy]>=0) 
		{
			if(f[xxx][yyy]==0) dfs(xxx,yyy,f[xx][yy]);
			else dfs(xxx,yyy,f[xxx][yyy]);
		}
		if(a<ff[xxx][yyy]&&a>-1) ff[xxx][yyy]=a;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ff[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r>>z;
		f[l][r]=z+1;
	}
	ff[1][1]=0;
	dfs(1,1,f[1][1]);
	cout<<ff[m][m];
	return 0;
}
