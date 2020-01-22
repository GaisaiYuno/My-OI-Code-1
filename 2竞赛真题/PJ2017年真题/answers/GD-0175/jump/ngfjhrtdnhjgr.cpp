#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 100
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m,x,y,c,i,j,map[110][110],ans[110][110],t,h,now,fx,fy,pp;
int f[12100][3],use[110][110];
bool vis[110][110];

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1; i<=m; i++) scanf("%d%d%d",&x,&y,&c),map[x][y]=c+1;
	for (i=1; i<=n; i++) for (j=1; j<=n; j++) ans[i][j]=INF;
	for (i=1; i<=n; i++) for (j=1; j<=n; j++) vis[i][j]=0;
	for (i=1; i<=n; i++) for (j=1; j<=n; j++) use[i][j]=0;
	h=t=1;
	f[1][1]=1;f[1][2]=1;vis[1][1]=1;ans[1][1]=0;
	while (h<=t)
	{
		x=f[h][1];y=f[h][2];
		now=map[x][y];
		for (i=0; i<4; i++)
		{
			fx=x+dx[i]; fy=y+dy[i];
			if (fx>0 && fx<=n && fy>0 && fy<=n && ans[fx][fy]>ans[x][y])
			{
				if (map[fx][fy]==0)
				{
					if (use[x][y]) continue;
					ans[fx][fy]=min(ans[fx][fy],ans[x][y]+2);
					if (use[fx][fy]==0) use[fx][fy]=now;
					else if (use[fx][fy]!=now) use[fx][fy]=3;
					t++;
					f[t][1]=fx;
					f[t][2]=fy;continue;
				}
				if (map[fx][fy]==now)
				{
					ans[fx][fy]=min(ans[fx][fy],ans[x][y]);
					t++;
					f[t][1]=fx;
					f[t][2]=fy;continue;
				}
				if (map[fx][fy]!=now)
				{
					if (map[x][y]==0)
					{
						if (use[x][y]==3 || use[x][y]==map[fx][fy]) ans[fx][fy]=min(ans[fx][fy],ans[x][y]);
					}
					ans[fx][fy]=min(ans[fx][fy],ans[x][y]+1);
					t++;
					f[t][1]=fx;
					f[t][2]=fy;continue;
				}	
			}
		}
		h++;
	}
	if (ans[n][n]==INF) printf("-1\n");else printf("%d\n",ans[n][n]);
	fclose(stdin);fclose(stdout);
	return 0;
}

