#include<cstdio>
#include<cstring>
using namespace std;
const int xx[4]={1,0,-1,0},
		  yy[4]={0,1,0,-1};
int map[110][110],n;
int f[110][110][2];
int abs(int x){if(x>0)return x; else return 0-x;}
int min(int x,int y){if(x<y)return x; else return y;}
void dfs(int x,int y,bool c,int now)
{
	if(f[x][y][c]<=now)return ;
	f[x][y][c]=now;
	int i,nx,ny,h;bool nc=(!c);
	for(i=0;i<4;i++)
	{
		nx=x+xx[i];ny=y+yy[i];
		if(map[nx][ny]==0&&nc)
		{
			map[nx][ny]=0-map[x][y];
			dfs(nx,ny,1,now+2);
			map[nx][ny]=0;
		}
		if(map[nx][ny]!=0)
		{
			h=map[x][y];
			if(map[x][y]<0)map[x][y]=0;
			if(abs(map[nx][ny])==abs(h))dfs(nx,ny,0,now);
			else dfs(nx,ny,0,now+1);
			map[x][y]=h;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,i;
	memset(map,0,sizeof(map));
	memset(f,334455,sizeof(f));
	scanf("%d%d",&n,&m);
	int x,y,c;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c+1;
	}
	dfs(1,1,0,0);
	printf("%d",min(f[n][n][1],f[n][n][0]));
	return 0;
}
