#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<int> qx,qy;
int m,n,x,y,hh,a[101][101],z[101][101];
bool b,g[101][101],h[101][101];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,-1,sizeof(a));
	scanf("%d%d",&m,&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d%d",&x,&y,&b),a[x][y]=b;
	qx.push(1);qy.push(1);h[1][1]=g[1][1]=1;
	while(!qx.empty())
	{
		x=qx.front(),y=qy.front(),b=0;
		if(x>1&&a[x-1][y]!=-1)
		{
			hh=a[x-1][y]==a[x][y]? 0:1;
			if(!g[x-1][y]||(z[x][y]+hh<z[x-1][y]&&!h[x-1][y]))
			{
				qx.push(x-1);qy.push(y);g[x-1][y]=h[x-1][y]=1;z[x-1][y]=z[x][y]+hh;
			}
		}
		if(y>1&&a[x][y-1]!=-1)
		{
			hh=a[x][y-1]==a[x][y]? 0:1;
			if(!g[x][y-1]||(z[x][y]+hh<z[x][y-1]&&!h[x][y-1]))
			{
				qx.push(x);qy.push(y-1);g[x][y-1]=h[x][y-1]=1;z[x][y-1]=z[x][y]+hh;
			}
		}
		if(x<m&&a[x+1][y]!=-1)
		{
			hh=a[x+1][y]==a[x][y]? 0:1;
			if(!g[x+1][y]||(z[x][y]+hh<z[x+1][y]&&!h[x+1][y]))
			{
				qx.push(x+1);qy.push(y);g[x+1][y]=h[x+1][y]=1;z[x+1][y]=z[x][y]+hh;
			}
		}
		if(y<m&&a[x][y+1]!=-1)
		{
			hh=a[x][y+1]==a[x][y]? 0:1;
			if(!g[x][y+1]||(z[x][y]+hh<z[x][y+1]&&!h[x][y+1]))
			{
				qx.push(x);qy.push(y+1);g[x][y+1]=h[x][y+1]=1;z[x][y+1]=z[x][y]+hh;
			}
		}
		if(x>1&&y>1&&a[x-1][y-1]!=-1&&a[x-1][y]==-1&&a[x][y-1]==-1)
		{
			hh=a[x-1][y-1]==a[x][y]? 2:3;
			if(!g[x-1][y-1]||(z[x][y]+hh<z[x-1][y-1]&&!h[x-1][y-1]))
			{
				qx.push(x-1);qy.push(y-1);g[x-1][y-1]=h[x-1][y-1]=1;z[x-1][y-1]=z[x][y]+hh;
			}
		}
		if(x>1&&y<m&&a[x-1][y+1]!=-1&&a[x-1][y]==-1&&a[x][y+1]==-1)
		{
			hh=a[x-1][y+1]==a[x][y]? 2:3;
			if(!g[x-1][y+1]||(z[x][y]+hh<z[x-1][y+1]&&!h[x-1][y+1]))
			{
				qx.push(x-1);qy.push(y+1);g[x-1][y+1]=h[x-1][y+1]=1;z[x-1][y+1]=z[x][y]+hh;
			}
		}
		if(x<m&&y>1&&a[x+1][y-1]!=-1&&a[x+1][y]==-1&&a[x][y-1]==-1)
		{
			hh=a[x+1][y-1]==a[x][y]? 2:3;
			if(!g[x+1][y-1]||(z[x][y]+hh<z[x+1][y-1]&&!h[x+1][y-1]))
			{
				qx.push(x+1);qy.push(y-1);g[x+1][y-1]=h[x+1][y-1]=1;z[x+1][y-1]=z[x][y]+hh;
			}
		}
		if(x<m&&y<m&&a[x+1][y+1]!=-1&&a[x+1][y]==-1&&a[x][y+1]==-1)
		{
			hh=a[x+1][y+1]==a[x][y]? 2:3;
			if(!g[x+1][y+1]||(z[x][y]+hh<z[x+1][y+1]&&!h[x+1][y+1]))
			{
				qx.push(x+1);qy.push(y+1);g[x+1][y+1]=h[x+1][y+1]=1;z[x+1][y+1]=z[x][y]+hh;
			}
		}
		if(x>2&&a[x-2][y]!=-1&&a[x-1][y]==-1)
		{
			hh=a[x-2][y]==a[x][y]? 2:3;
			if(!g[x-2][y]||(z[x][y]+hh<z[x-2][y]&&!h[x-2][y]))
			{
				qx.push(x-2);qy.push(y);g[x-2][y]=h[x-2][y]=1;z[x-2][y]=z[x][y]+hh;
			}
		}
		if(x<m-1&&a[x+2][y]!=-1&&a[x+1][y]==-1)
		{
			hh=a[x+2][y]==a[x][y]? 2:3;
			if(!g[x+2][y]||(z[x][y]+hh<z[x+2][y]&&!h[x+2][y]))
			{
				qx.push(x+2);qy.push(y);g[x+2][y]=h[x+2][y]=1;z[x+2][y]=z[x][y]+hh;
			}
		}
		if(y>2&&a[x][y-2]!=-1&&a[x][y-1]==-1)
		{
			hh=a[x][y-2]==a[x][y]? 2:3;
			if(!g[x][y-2]||(z[x][y]+hh<z[x][y-2]&&!h[x][y-2]))
			{
				qx.push(x);qy.push(y-2);g[x][y-2]=h[x][y-2]=1;z[x][y-2]=z[x][y]+hh;
			}
		}
		if(y<m-1&&a[x][y+2]!=-1&&a[x][y+1]==-1)
		{
			hh=a[x][y+2]==a[x][y]? 2:3;
			if(!g[x][y+2]||(z[x][y]+hh<z[x][y+2]&&!h[x][y+2]))
			{
				qx.push(x);qy.push(y+2);g[x][y+2]=h[x][y+2]=1;z[x][y+2]=z[x][y]+hh;
			}
		}
		if((x==m-1&&y==m||x==m&&y==m-1)&&a[m][m]==-1)
		{
			qx.push(m);qy.push(m);g[m][m]=h[m][m]=1;z[m][m]=z[x][y]+2;
		}
		h[x][y]=0;
		qx.pop();qy.pop();
	}
	if(g[m][m]) printf("%d\n",z[m][m]);
	else printf("-1\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
