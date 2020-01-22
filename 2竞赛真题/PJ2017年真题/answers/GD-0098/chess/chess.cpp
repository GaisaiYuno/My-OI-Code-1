#include <iostream>
#include <cstdio>
using namespace std;
struct TNODE{
	int x,y;
};
TNODE qu[1000005];
const int oo=2147000000;
int dx[4]={1,0,-1,0},
	dy[4]={0,1,0,-1};
int n,h,biao[1005][1005],m[1005][1005],m2[1005][1005],f[1005][1005],p=0;
void Bfs()
{
	int tai=1,hea=1;
	qu[tai].x=1;
	qu[tai].y=1;
	biao[1][1]=1;
	while (hea<=tai)
		{
			for (int i=0;i<4;i++)
				{
					int cx=qu[hea].x+dx[i],
						cy=qu[hea].y+dy[i];
					if (cx>0&&cx<=n&&cy>0&&cy<=n)
						{
							p=0;
							if (m[cx][cy]&&m[qu[hea].x][qu[hea].y])	
								{
									if (m[cx][cy]==m[qu[hea].x][qu[hea].y])
										f[cx][cy]=min(f[cx][cy],f[qu[hea].x][qu[hea].y]);
									else
										f[cx][cy]=min(f[qu[hea].x][qu[hea].y]+1,f[cx][cy]);
									p=1;
								}
							else
								if (m[cx][cy]&&!m[qu[hea].x][qu[hea].y])
									{
										if (m[cx][cy]==m2[qu[hea].x][qu[hea].y])
											f[cx][cy]=min(f[qu[hea].x][qu[hea].y],f[cx][cy]);
										else
											f[cx][cy]=min(f[cx][cy],f[qu[hea].x][qu[hea].y]+1);
										p=1;
									}
							else
								if (!m[cx][cy]&&m[qu[hea].x][qu[hea].y])
									{
										if (f[cx][cy]>f[qu[hea].x][qu[hea].y]+2)
											m2[cx][cy]=m[qu[hea].x][qu[hea].y];
										f[cx][cy]=min(f[qu[hea].x][qu[hea].y]+2,f[cx][cy]);
										p=1;
									}
							if (biao[cx][cy]==0&&p==1)
								{
									tai++;
									qu[tai].x=cx;
									qu[tai].y=cy;
									biao[cx][cy]=1;	
								}			
						}
				}
			if (!m[qu[hea].x][qu[hea].y]) m2[qu[hea].x][qu[hea].y]=0;
			hea++;
		}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=oo,m[i][j]=0,m2[i][j]=0,biao[i][j]=0;
	f[1][1]=0;
	for (int i=1,x,y,col;i<=h;i++)
		{
			scanf("%d%d%d",&x,&y,&col);
			m[x][y]=col+1;
		}
	Bfs();
	if (f[n][n]!=oo)
		cout << f[n][n];
	else
		cout << -1;
	return 0;
}
