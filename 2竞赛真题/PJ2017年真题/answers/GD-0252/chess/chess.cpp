#include<iostream>
#include<cstdio>
using namespace std;
int m,n,x,y,c,mp[105][105],dp[105][105],gai[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&c);
		mp[x][y]=c+1;
	}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
			dp[i][j]=10000000;
	dp[1][1]=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
		{
			if(mp[i][j])
			{
				if(mp[i+1][j]) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(mp[i][j]!=mp[i+1][j]));
				else
				{
					if(dp[i+1][j]>dp[i][j]+2)
					{
						dp[i+1][j]=dp[i][j]+2;
						gai[i+1][j]=mp[i][j];
					}
				}
				if(mp[i][j+1]) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(mp[i][j]!=mp[i][j+1]));
				else
				{
					if(dp[i][j+1]>dp[i][j]+2)
					{
						dp[i][j+1]=dp[i][j]+2;
						gai[i][j+1]=mp[i][j];
					}
				}
				if(mp[i-1][j]) dp[i-1][j]=min(dp[i-1][j],dp[i][j]+(mp[i][j]!=mp[i-1][j]));
				else
				{
					if(dp[i-1][j]>dp[i][j]+2)
					{
						dp[i-1][j]=dp[i][j]+2;
						gai[i-1][j]=mp[i][j];
					}
				}
				if(mp[i][j-1]) dp[i][j-1]=min(dp[i][j-1],dp[i][j]+(mp[i][j]!=mp[i][j-1]));
				else
				{
					if(dp[i][j-1]>dp[i][j]+2)
					{
						dp[i][j-1]=dp[i][j]+2;
						gai[i][j-1]=mp[i][j];
					}
				}
			}
			else
			{
				if(mp[i+1][j]) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(gai[i][j]!=mp[i+1][j]));
				if(mp[i][j+1]) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(gai[i][j]!=mp[i][j+1]));
				if(mp[i-1][j]) dp[i-1][j]=min(dp[i-1][j],dp[i][j]+(gai[i][j]!=mp[i-1][j]));
				if(mp[i][j-1]) dp[i][j-1]=min(dp[i][j-1],dp[i][j]+(gai[i][j]!=mp[i][j-1]));
			}
		}
	if(dp[m][m]!=10000000) printf("%d\n",dp[m][m]);
	else printf("-1\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
