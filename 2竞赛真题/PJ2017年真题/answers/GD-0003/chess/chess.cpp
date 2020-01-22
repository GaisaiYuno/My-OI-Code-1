#include<cstdio>
#include<cstdlib>
using namespace std;
const int MAXN=2e9;
int map[103][103]={{0}},x,y,c,dp[4][2]={{1,0},{0,1},{-1,0},{0,-1}},step[103][103],m,n;
void Search(int x,int y,int coin,bool magic)
{
	if(step[x][y]>coin) 
	{
		int now=map[x][y];
		step[x][y]=coin;
		for(int i=0;i<4;i++)
		{
			if(step[x+dp[i][0]][y+dp[i][1]]>=0) 
			{
				if(map[x+dp[i][0]][y+dp[i][1]]==0 && magic && coin+2<step[x+dp[i][0]][y+dp[i][1]])
				{
					map[x+dp[i][0]][y+dp[i][1]]=map[x][y];
					Search(x+dp[i][0],y+dp[i][1],coin+2,false);
				}
				if(map[x+dp[i][0]][y+dp[i][1]]!=map[x][y] && map[x+dp[i][0]][y+dp[i][1]]!=0 )
				{
					if(!magic)
						map[x][y]=0;
					Search(x+dp[i][0],y+dp[i][1],coin+1,true);
				}
				if(map[x+dp[i][0]][y+dp[i][1]]==now)
				{
					if(!magic) 
						map[x][y]=0;
					Search(x+dp[i][0],y+dp[i][1],coin,true);
				}
			}
		}
	} 
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&c);
		map[x][y]=c+1;
	}
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(i==0||j==0||i==m+1||j==m+1) step[i][j]=-MAXN;
			else step[i][j]=MAXN;
		}
	}
	Search(1,1,0,true);
	if(step[m][m]==MAXN) printf("-1");
	else printf("%d",step[m][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
