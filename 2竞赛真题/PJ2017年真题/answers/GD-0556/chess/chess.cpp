#include<cstdio>
#include<iostream>
#include<cstring>
int map[110][110],mmin[110][110],mmap[110][110];
bool b[110][110]; 
int tx[4]={0,1,0,-1},n;
int ty[4]={1,0,-1,0};
int mymin(int x,int y){return x<y?x:y;}
void dfs(int x,int y,int mon) 
{
	if(mmin[x][y]==-1 || mmin[x][y]>mon) mmin[x][y]=mon;
	if(mmin[x][y]!=-1 && mmin[x][y]<mon) return ;
	if(x==n && y==n) return ;
	for(int i=0;i<=3;i++)
	{
		if(x+tx[i]>=1 && x+tx[i]<=n && y+ty[i]>=1 && ty[i]+y<=n && b[tx[i]+x][ty[i]+y]==false)
		{
			if(map[x][y]==-1)
			{
				if(map[tx[i]+x][ty[i]+y]!=-1)
				{
					b[tx[i]+x][ty[i]+y]=true;
					if(map[tx[i]+x][ty[i]+y]==mmap[x][y]) dfs(x+tx[i],y+ty[i],mon);
					else dfs(x+tx[i],y+ty[i],mon+1);
					b[tx[i]+x][ty[i]+y]=false;
				}
			}
			else
			{
				b[tx[i]+x][ty[i]+y]=true;
				if(map[tx[i]+x][ty[i]+y]!=-1)
				{
					if(map[tx[i]+x][ty[i]+y]==map[x][y]) dfs(x+tx[i],y+ty[i],mon);
					else dfs(x+tx[i],y+ty[i],mon+1);
				}
				else 
				{
					mmap[tx[i]+x][ty[i]+y]=map[x][y];
					dfs(x+tx[i],y+ty[i],mon+2);
				}
				b[tx[i]+x][ty[i]+y]=false;
			}
		}
	}
	return ;
}                                                         
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,x,y,z;
	scanf("%d%d",&n,&m);
	memset(map,-1,sizeof(map));
	memset(b,false,sizeof(b));
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&x,&y,&z);
		mmap[x][y]=map[x][y]=z;
	}
	memset(mmin,-1,sizeof(mmin));
	dfs(1,1,0);
	printf("%d\n",mmin[n][n]);
	return 0;
}
