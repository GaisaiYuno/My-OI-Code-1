#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100+5][100+5],opens[100+5][100+5],x,y,o,f[100+5][100+5],pf,p,ans=-1;
void fs(int x,int y,int f)
{
	if(x==m&&y==m) ans=f;
	if(a[x][y]==0) return;
	if(x+1<=m)
	{
		if(a[x+1][y]!=a[x][y]&&a[x][y]>0&&a[x+1][y]>0) fs(x+1,y,f+1);
		if(a[x+1][y]==a[x][y]&&a[x][y]>0) fs(x+1,y,f);
	}
		
	if(y+1<=m)
	{
		if(a[x][y+1]!=a[x][y]&&a[x][y]>0&&a[x][y+1]>0) fs(x,y+1,f+1);
		if(a[x][y+1]==a[x][y]&&a[x][y]>0) fs(x,y+1,f);
	}
	

}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>o;
		a[x][y]=o+1;
	}
	fs(1,1,0);
	cout<<ans;
	return 0;
}
