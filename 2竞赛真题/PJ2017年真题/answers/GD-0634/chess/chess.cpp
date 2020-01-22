#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[210][210],f[210][210],color[210][210];
bool v[210][210];
int tx[4]={0,1,0,-1};
int ty[4]={1,0,-1,0};
struct node
{
	int x,y;
}list[66600];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(f,127/3,sizeof(f));
	memset(a,0,sizeof(a));
	memset(v,true,sizeof(v));
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&a[x][y]);
		a[x][y]++;
	}
	f[m][m]=0;
	v[m][m]=false;
	list[1].x=list[1].y=m;
	color[m][m]=0;
	int head=1,tail=1;
	while(head<=tail)
	{	
		int x=list[head].x,y=list[head].y;
		for(int t=0;t<=3;t++)
		{
			bool b=false;
			int xx=list[head].x+tx[t],yy=list[head].y+ty[t];
			if(xx>=1&&xx<=m&&yy>=1&&yy<=m)
			{
				if(a[x][y]==a[xx][yy])
				{
					if(a[x][y]!=0)
					{
						if(f[xx][yy]>f[x][y])
						{
							f[xx][yy]=f[x][y];
							b=true;
						}
					}
				}
				else 
				{
					if(a[xx][yy]==0)
					{
						if(f[xx][yy]>f[x][y]+2)
						{
							f[xx][yy]=f[x][y]+2;
							color[xx][yy]=a[x][y];
							b=true;
						}
					}
					else if(a[x][y]==0)
					{
						if(color[x][y]==0)
						{
							if(f[xx][yy]>f[x][y]+2)
							{
								f[xx][yy]=f[x][y]+2;
								b=true;
							}
						}
						else if(color[x][y]==a[xx][yy])
						{
							if(f[xx][yy]>f[x][y])
							{
								f[xx][yy]=f[x][y];
								b=true;
							}
						}
						else
						{
							if(f[xx][yy]>f[x][y]+1)
							{
								f[xx][yy]=f[x][y]+1;
								b=true;
							}
						}
					}
					else
					{
						if(f[xx][yy]>f[x][y]+1)
						{
							f[xx][yy]=f[x][y]+1;
							b=true;
						}
					}
				}
				if(b==true)
				{				
					if(v[xx][yy]==true)
					{
						v[xx][yy]=false;
						list[++tail].x=xx;
						list[tail].y=yy;
					}
				}
			}
		}
		v[x][y]=true;
		head++;
	}
	if(f[1][1]==707406378)printf("-1\n");
	else printf("%d\n",f[1][1]);
	return 0;
}
