#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],dp[110][110][3][3],ans;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	    for (int j=1;j<=m;j++) a[i][j]=-1;
	for (int i=1;i<=n;i++) 
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	memset(dp,0x6f,sizeof(dp));
	dp[1][1][a[1][1]][0]=0;
	for (int i=1;i<=m;i++)
	    for (int j=1;j<=m;j++) if (i!=1||j!=1)
	    {
	    	if (j>1)
	    	{
	    		if (a[i][j]==1) 
				{
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j-1][1][0]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j-1][1][1]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j-1][0][0]+1);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j-1][0][1]+1);
				}
				if (a[i][j]==0)
				{
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j-1][0][1]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j-1][0][0]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j-1][1][1]+1);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j-1][1][0]+1);
				}
				if (a[i][j]==-1)
				{
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i][j-1][0][0]+3);
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i][j-1][1][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i][j-1][0][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i][j-1][1][0]+3);
				}
	    	}
	    	if (i>1)
	    	{
	    		if (a[i][j]==1) 
				{
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i-1][j][1][0]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i-1][j][1][1]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i-1][j][0][0]+1);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i-1][j][0][1]+1);
				}
				if (a[i][j]==0)
				{
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i-1][j][0][1]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i-1][j][0][0]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i-1][j][1][1]+1);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i-1][j][1][0]+1);
				}
				if (a[i][j]==-1)
				{
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i-1][j][0][0]+3);
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i-1][j][1][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i-1][j][0][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i-1][j][1][0]+3);
				}
	    	}
	    	if (j<m)
	    	{
	    		if (a[i][j]==1) 
				{
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j+1][1][0]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j+1][1][1]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j+1][0][0]+1);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i][j+1][0][1]+1);
				}
				if (a[i][j]==0)
				{
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j+1][0][1]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j+1][0][0]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j+1][1][1]+1);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i][j+1][1][0]+1);
				}
				if (a[i][j]==-1)
				{
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i][j+1][0][0]+3);
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i][j+1][1][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i][j+1][0][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i][j+1][1][0]+3);
				}
	    	}
	    	if (i<m)
	    	{
	    		if (a[i][j]==1) 
				{
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i+1][j][1][0]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i+1][j][1][1]);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i+1][j][0][0]+1);
					dp[i][j][1][0]=min(dp[i][j][1][0],dp[i+1][j][0][1]+1);
				}
				if (a[i][j]==0)
				{
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i+1][j][0][1]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i+1][j][0][0]);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i+1][j][1][1]+1);
					dp[i][j][0][0]=min(dp[i][j][0][0],dp[i+1][j][1][0]+1);
				}
				if (a[i][j]==-1)
				{
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i+1][j][0][0]+3);
					dp[i][j][1][1]=min(dp[i][j][1][1],dp[i+1][j][1][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i+1][j][0][0]+2);
					dp[i][j][0][1]=min(dp[i][j][0][1],dp[i+1][j][1][0]+3);
				}
	    	}
	    }
	ans=min(dp[m][m][a[m][m]][0],dp[m][m][a[m][m]][1]);
	if (ans>40000) printf("-1");
	else printf("%d",ans);
	return 0;
}
