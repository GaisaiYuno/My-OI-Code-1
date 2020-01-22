#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[205][205],f[205][205],g[205][205][2],x,y,z,p[2]={-1,0},q[2]={0,-1},bz[205][205];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=2;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),a[x][y]=z;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=1000000000,g[i][j][0]=1000000000,g[i][j][1]=1000000000;
	f[1][1]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<2;k++)
			{
				x=i+p[k],y=j+q[k];
				if (x>0&&x<=n&&y>0&&y<=n)
				{
					if (a[i][j]==2) 
					{
						if (a[x][y]==1) g[i][j][1]=min(g[i][j][1],f[x][y]+2),g[i][j][0]=min(g[i][j][0],f[x][y]+3);
						if (a[x][y]==0) g[i][j][1]=min(g[i][j][1],f[x][y]+3),g[i][j][0]=min(g[i][j][0],f[x][y]+2);
					}
					if (a[i][j]==1)
					{
						if (a[x][y]==1) f[i][j]=min(f[i][j],f[x][y]);
						if (a[x][y]==0) f[i][j]=min(f[i][j],f[x][y]+1);
						if (a[x][y]==2) f[i][j]=min(f[i][j],min(g[x][y][1],g[x][y][0]+1));
					}
					if (a[i][j]==0)
					{
						if (a[x][y]==0) f[i][j]=min(f[i][j],f[x][y]);
						if (a[x][y]==1) f[i][j]=min(f[i][j],f[x][y]+1);
						if (a[x][y]==2) f[i][j]=min(f[i][j],min(g[x][y][1]+1,g[x][y][0]));			
					}
				}
			}
	int T=min(f[n][n],g[n][n][0]);
	T=min(T,g[n][n][1]);
	if (T==1000000000) printf("-1");
	else printf("%d",T);			
}
