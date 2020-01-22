#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[5]={0,1,0,-1};
const int dy[5]={1,0,-1,0};
int a[105][105];
bool b[105][105];
int n,m,ans=0;
int dfs(int x,int y,int co,bool u)
{
	if(x==n&&y==n)return 0;
	b[x][y]=1;
	int mn=20000;
	for(int i=0;i<4;i++)if(x+dx[i]<=n&&x+dx[i]>=1&&y+dy[i]<=n&&y+dy[i]>=1&&(!b[x+dx[i]][y+dy[i]]))
	{
		if(a[x+dx[i]][y+dy[i]]!=-1)mn=min(mn,dfs(x+dx[i],y+dy[i],a[x+dx[i]][y+dy[i]],1)+abs(co-a[x+dx[i]][y+dy[i]]));
		else if(a[x+dx[i]][y+dy[i]]==-1&&u)
		{
			mn=min(mn,dfs(x+dx[i],y+dy[i],0,0)+2);
			mn=min(mn,dfs(x+dx[i],y+dy[i],1,0)+2);
		}
	}
	return mn;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(int i=0;i<105;i++)
	for(int j=0;j<105;j++)a[i][j]=-1;
	for(int i=0;i<105;i++)
	for(int j=0;j<105;j++)b[i][j]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	ans=dfs(1,1,a[1][1],1);
	if(ans>=20000)printf("-1");
	else printf("%d",ans);
	return 0;
}
