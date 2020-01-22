#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10001][1001],ans[1001][1001];
int dif(int x,int y)
{
	if (a[x][y]!=-1&&(a[x+1][y]!=-1||a[x][y+1]!=-1)) 
	{
		ans[x+1][y]=dif(x+1,y);
	    if (a[x][y]==a[x+1][y]) return 0;
	    if (a[x][y]-a[x+1][y]==1||a[x+1][y]-a[x][y]==1) return 1;
	    if (a[x][y]!=a[x+1][y]&&a[x+1][y]==-1) 
	    {
	    	if (a[x][y]==1) a[x+1][y]=1;
	    	if (a[x][y]==0) a[x+1][y]=0;
	    	return 2;
    	}
    	ans[x][y+1]=dif(x,y+1);
	    if (a[x][y]==a[x][y+1]) return 0;
	    if (a[x][y]-a[x][y+1]==1||a[x][y+1]-a[x][y+1]==1) return 1;
	    if (a[x][y]!=a[x][y+1]&&a[x][y+1]==-1) 
	    {
	    	if (a[x][y]==1) a[x][y+1]=1;
	    	if (a[x][y]==0) a[x][y+1]=0;
	    	return 2;
    	}
    	ans[x][y]+=min(ans[x+1][y],ans[x][y+1]);
	}
	return -1;
}
int k[1001],f[1001],n,m,c[1001];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=m;j++)
	a[i][j]=-1;
	for (int i=1;i<=n;i++)
	{
		cin>>k[i]>>f[i]>>c[i];
		a[k[i]][f[i]]=c[i];
	}
	
	if (ans[1][1]!=0) cout<<ans[1][1];
	             else cout<<dif(1,1);
	return 0;
}
