#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int xx[5]={0,1,0,-1,0},yy[5]={0,0,1,0,-1};
int f[105][105],m,n,x,y,z,ans;
bool f1[105][105];
void dfs(int x,int y,int u,int mg)
{
	if(x==m&&y==m)
	{
		ans=min(ans,u);
		return ;
	}
	for(int i=1;i<=4;i++)
	{int x1=x+xx[i],y1=y+yy[i];
	int l=u;
		if(x1<=m&&y1<=m&&f[x1][y1]>0&&!f1[x1][y1])
		{
			if(f[x1][y1]!=f[x][y]) l=l+1;
			f1[x1][y1]=true;
			dfs(x1,y1,l,1);
			f1[x1][y1]=false;
		}
		else if(x1<=m&&y1<=m&&!f1[x1][y1]&&mg==1)
		{
			 l+=2;
			f1[x1][y1]=true;
			f[x1][y1]=f[x][y];
			dfs(x1,y1,l,0);
			f[x1][y1]=0;
			f1[x1][y1]=false;
		}
	}
	return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		f[x][y]=z+1;
	}
	ans=2147483647;
	dfs(1,1,0,1);
	if(ans==2147483647)cout<<"-1";
	else cout<<ans;
	return  0;
}
