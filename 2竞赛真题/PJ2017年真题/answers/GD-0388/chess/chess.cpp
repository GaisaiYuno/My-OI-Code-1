#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 2147483647
using namespace std;
int n,m,x,y,c,a[101][101],f[101][101],mx[5]={0,0,1,0,-1},my[5]={0,1,0,-1,0},mmp[101][101];
bool b[101][101],uds[101][101];
queue <int> p,q;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,0,sizeof(a));
	int i,j,k;
	scanf("%d%d",&m,&n);
	for (i=1;i<=m;i++)
		for (j=1;j<=m;j++)
			f[i][j]=INF;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		if (c==1)
			a[x][y]=1;
		else
			a[x][y]=2;
	}
	b[1][1]=1;
	p.push(1);
	q.push(1);
	f[1][1]=0;
	while (!q.empty()&&!p.empty())
	{
		int nx=p.front(),ny=q.front();
		p.pop();
		q.pop();
//		b[nx][ny]=0;
		for (i=1;i<=4;i++)
			if (nx+mx[i]>=1&&nx+mx[i]<=m&&ny+my[i]>=1&&ny+my[i]<=m&&(!b[nx+mx[i]][ny+my[i]]))
			{
				int ux=nx+mx[i],uy=ny+my[i];
				if (a[nx][ny])
				{
					if (a[ux][uy])
					{
						if (a[nx][ny]==a[ux][uy])
						{
							f[ux][uy]=min(f[nx][ny],f[ux][uy]);
							uds[ux][uy]=0;
							if (b[ux][uy])
								break;
							b[ux][uy]=1;
							p.push(ux);
							q.push(uy);
						}
						else
						{
							f[ux][uy]=min(f[nx][ny]+1,f[ux][uy]);
//							f[ux][uy]=min()
							uds[ux][uy]=0;
							if (b[ux][uy])
								break;
							b[ux][uy]=1;
							p.push(ux);
							q.push(uy);
						}
					}
					else
					{
						if (a[nx][ny]/*&&!uds[nx][ny]*/&&f[nx][ny]+2<f[ux][uy])
						{
							f[ux][uy]=f[nx][ny]+2;
							uds[ux][uy]=1;
							mmp[ux][uy]=a[nx][ny];
							if (b[ux][uy])
								break;
							b[ux][uy]=1;
							p.push(ux);
							q.push(uy);
						}
					}
				}
				else
				{
					if (a[ux][uy]/*&&!uds[nx][ny]*/)
					{
						if (a[ux][uy]==mmp[nx][ny])
							f[ux][uy]=min(f[nx][ny],f[ux][uy]);
						else
							f[ux][uy]=min(f[nx][ny]+1,f[ux][uy]);
						if (b[ux][uy])	
							break;
						b[ux][uy]=1;
						p.push(ux);
						q.push(uy);
					}
				}
			}
//		for (i=1;i<=m;i++)
//		{
//			for (j=1;j<=m;j++)
//				printf("%d\t",f[i][j]);
//			printf("\n");
//		}
//		printf("\n\n");
	}
	if (f[m][m]==INF)
		printf("-1");
	else
		printf("%d",f[m][m]);
//	printf("\n%d",f[3][2]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
