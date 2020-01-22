#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
const int INF=2e9;
using namespace std;
int a[105][105];
int n,m,i,j;
int c[105][105];
int s;
int zl[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int tempx,tempy;
void dfs(int x,int y,int cl)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(c[x][y]!=-1)
		{
			if(c[x+zl[i][0]][y+zl[i][1]]!=-1)
			{
				if(c[x+zl[i][0]][y+zl[i][1]]==c[x][y]&&a[x][y]<a[x+zl[i][0]][y+zl[i][1]])
				{
					a[x+zl[i][0]][y+zl[i][1]]=a[x][y];
					dfs(x+zl[i][0],y+zl[i][1],5);
				}
				if(c[x+zl[i][0]][y+zl[i][1]]!=c[x][y]&&a[x][y]+1<a[x+zl[i][0]][y+zl[i][1]])
				{
					a[x+zl[i][0]][y+zl[i][1]]=a[x][y]+1;
					dfs(x+zl[i][0],y+zl[i][1],5);
				}
			}
			else 
			{
				if(a[x][y]+2<a[x+zl[i][0]][y+zl[i][1]])
				{
					a[x+zl[i][0]][y+zl[i][1]]=a[x][y]+2;
					dfs(x+zl[i][0],y+zl[i][1],c[x][y]);
				}
			}
		}
		if(c[x][y]==-1)
		{
			if(c[x+zl[i][0]][y+zl[i][1]]==cl&&a[x][y]<a[x+zl[i][0]][y+zl[i][1]])
			{
				a[x+zl[i][0]][y+zl[i][1]]=a[x][y];
				dfs(x+zl[i][0],y+zl[i][1],5);
			}
			if(c[x+zl[i][0]][y+zl[i][1]]!=cl&&c[x+zl[i][0]][y+zl[i][1]]!=-1&&a[x][y]+1<a[x+zl[i][0]][y+zl[i][1]])
			{
				a[x+zl[i][0]][y+zl[i][1]]=a[x][y]+1;
				dfs(x+zl[i][0],y+zl[i][1],5);
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(i=0;i<105;i++)
	{
		for(j=0;j<105;j++)
		{
			a[i][j]=INF;
			c[i][j]=-1;
		}
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&tempx,&tempy,&s);
		c[tempx+1][tempy+1]=s;
	}
	a[2][2]=0;
	dfs(2,2,5);
if(a[n+1][n+1]!=INF) printf("%d",a[n+1][n+1]);
else printf("-1");
fclose(stdin);
fclose(stdout);
return 0;
}

