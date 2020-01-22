#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=100000000;
int g[103][103],Count[10001]={0},Can[10001]={false},d[4][2]={{1,0},{0,-1},{-1,0},{0,1}},Drive=0;
bool flag=false,cd=true;
int m,n;
void dfs(int x,int y)
{
	bool got=false;
	if(x==m && y==m)
	{
		Can[Drive]=true;
		Drive++;
		flag=true;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			if(g[x+d[i][0]][y+d[i][1]]==0 || g[x+d[i][0]][y+d[i][1]]==1)
			{
				if(g[x][y]!=g[x+d[i][0]][y+d[i][1]])
				{
					Count[Drive]++;
					cd=true;
					got=true;
					dfs(x+d[i][0],y+d[i][1]);
				}
				else
				{
					cd=true;
					got=true;
					dfs(x+d[i][0],y+d[i][1]);
				}
			}
			else if(g[x+d[i][0]][y+d[i][1]]==2)
			{
				if(cd==true)
				{
					cd=false;
					got=true;
					dfs(x+d[i][0],y+d[i][1]);
				}
			}
		}
		if(got!=true) Drive++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,c,ans=INF;
	scanf("%d%d",&m,&n);
	memset(Can,false,sizeof(Can));
	for(int i=0;i<=103;i++)
	{
		for(int j=0;j<=103;j++)
		{
			if(i>=1 && j>=1 && i<=m && j<=m) g[i][j]=2;
			else g[i][j]=3;
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		g[x][y]=c;
	}
	/**************/
//	dfs(1,1);
//	if(flag)
//	{
//		for(int i=0;i<Drive;i++)
//		{
//			if(Can[i]) ans=min(ans,Count[i]);
//		}
//		printf("%d",ans);
//	}
	/*else*/ printf("-1");
	ans++;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
