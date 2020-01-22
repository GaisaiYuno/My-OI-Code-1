#include <cstdio>
#include <cstring>

int a[110][110];
int f[110][110];
struct node{int x,y,z,s;};
node q[1000100];
int n,m;
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=999999999;
			a[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		a[x][y]=z+1;
	}
	int st=1,ed=2;
	q[st].x=1;
	q[st].y=1;
	q[st].z=0;
	q[st].s=a[1][1];
	f[1][1]=0;
	while(st!=ed)
	{
		int x=q[st].x,y=q[st].y,z=q[st].z;
		for(int i=0;i<4;i++)
		{
			int xx=x+fx[i],yy=y+fy[i];
			if(xx<1||xx>n||yy<1||yy>n)continue;
			if(a[xx][yy]==0)
			{
				if(a[x][y]==0)continue;
				else
				{
					if(z+2<f[xx][yy])f[xx][yy]=z+2;
					else continue;
					q[ed].x=xx;
					q[ed].y=yy;
					q[ed].z=z+2;
					if(q[st].s!=1)q[ed].z++;
					q[ed].s=1;
					ed++;
					q[ed].x=xx;
					q[ed].y=yy;
					q[ed].z=z+2;
					if(q[st].s!=2)q[ed].z++;
					q[ed].s=2;
					ed++;
				}
			}
			else
			{
				if(q[st].s==a[xx][yy]&&z<f[xx][yy])
				{
					f[xx][yy]=z;
					q[ed].x=xx;
					q[ed].y=yy;
					q[ed].z=z;
					q[ed++].s=q[st].s;
				}
				else
				{
					if(z+1<f[xx][yy])f[xx][yy]=z+1;
					else continue;
					q[ed].x=xx;
					q[ed].y=yy;
					q[ed].z=z+1;
					q[ed++].s=a[xx][yy];
				}
			}
		}
		st++;
	}
	if(f[n][n]!=999999999)printf("%d",f[n][n]);
	else printf("-1");
}
