#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int maze[300][300],f[10000+200][10],minn[300][300];
int dir[5][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1}};
bool bz[300][300];
void bfs()
{
	int i=0,j=1;
	f[1][1]=1;
	f[1][2]=1;
	f[1][3]=maze[1][1];
	minn[1][1]=0;
	while(i<j)
	{
		i++;
		for(int k=1;k<=4;k++)
		{
			int p=f[i][1],q=f[i][2],value=0;
			p+=dir[k][0],q+=dir[k][1];
			if(p>=1&&p<=n&&q>=1&&q<=n)
			{
				j++;
				f[j][1]=p;
				f[j][2]=q;
				if(maze[p][q]==f[i][3])
				{
					value=f[i][4];
					f[j][3]=maze[p][q];
				}
				else
				{
					if(maze[p][q]!=0)
					{
						value=f[i][4]+1;
						f[j][3]=maze[p][q];
					}
					else
					{
						value=f[i][4]+2;
						f[j][3]=f[i][3];
					}
				}
				if(maze[f[i][1]][f[i][2]]==0&&maze[p][q]==0)
					j--;
				else
				{
					if(bz[p][q])
					{
						if(value<minn[p][q])
						{
							f[j][4]=value;
							minn[p][q]=value;
						}
						else
							j--;
					}
					else
					{
						bz[p][q]=1;
						f[j][4]=value;
						minn[p][q]=value;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(z==0)
		{
			maze[x][y]=1;
		}
		if(z==1)
		{
			maze[x][y]=2;
		}
	}
	bfs();
	if(bz[n][n]==0)
		printf("-1");
	else
		printf("%d",minn[n][n]);
}
