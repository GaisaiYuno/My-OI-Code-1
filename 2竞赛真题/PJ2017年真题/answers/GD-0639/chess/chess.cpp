#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
inline int getint()
{
	int r=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
		f=c=='-'?-f:f,c=getchar();
	while (c>='0'&&c<='9')
		r=(r<<3)+(r<<1)+(c^'0'),c=getchar();
	return r*f;
}
int g[101][101],m,n,ans=0x7fffffff;
bool b[101][101];
const int dx[]={0x7fffffff,1,-1,0,0},dy[]={0x7fffffff,0,0,1,-1};
void dfs(int i,int j,int c,int w)
{
//	printf("%d %d %d %d %d\n",i,j,c,w,ans);
	if (ans<=w)
		return;
	if (i==m&&j==m)
	{
		ans=min(ans,w);
		return;
	}
	for (int k=1;k<=4;++k)
		if (!b[i+dx[k]][j+dy[k]]&&i+dx[k]>=1&&i+dx[k]<=m&&j+dy[k]>=1&&j+dy[k]<=m)
		{
			if (g[i+dx[k]][j+dy[k]]>=0)
			{
				b[i+dx[k]][j+dy[k]]=true;
				dfs(i+dx[k],j+dy[k],g[i+dx[k]][j+dy[k]],w+(c!=g[i+dx[k]][j+dy[k]]));
				b[i+dx[k]][j+dy[k]]=false;
			}
			else
				if (g[i][j]!=-1)
				{
					b[i+dx[k]][j+dy[k]]=true;
					dfs(i+dx[k],j+dy[k],c,w+2);
					b[i+dx[k]][j+dy[k]]=false;
				}
		}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	m=getint(),n=getint();
	int x,y,ans=1;
	memset(g,-1,sizeof g);
	for (int i=1;i<=n;++i)
		x=getint(),y=getint(),g[x][y]=getint();
	b[1][1]=true;
	dfs(1,1,g[1][1],0);
	if (ans==0x7fffffff)
		puts("-1");
	else
		printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
