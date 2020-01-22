#include<bits/stdc++.h>
using namespace std;
const int fx[4]={1,0,-1,0};
const int fy[4]={0,-1,0,1};
int dp[101][101],cl[101][101],x,y,c,m,n,p,q;
struct frm
{
	int a;
	int b;
}fm[101][101];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(dp,127/3,sizeof(dp));
	memset(cl,-1,sizeof(cl));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		cl[x][y]=c;
	}
	dp[1][1]=0;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	for(int k=0;k<4;k++)
	{
		p=i+fx[k];q=j+fy[k];
		if(p==0||q==0||p==m+1||q==m+1)continue;
		if(cl[i][j]==cl[p][q])
			if(cl[i][j]!=-1)dp[p][q]=min(dp[p][q],dp[i][j]);
		if(cl[i][j]!=cl[p][q])
		{
			if(cl[i][j]==-1)
			{
				if(cl[fm[i][j].a][fm[i][j].b]!=cl[p][q])
				dp[p][q]=min(dp[p][q],dp[i][j]+1);
				else dp[p][q]=min(dp[p][q],dp[i][j]);
			}
			if(cl[p][q]==-1)
			{
				if(dp[i][j]+2<dp[p][q])
				{
					fm[p][q].a=i;
					fm[p][q].b=j;
					dp[p][q]=dp[i][j]+2;
				}
				else dp[p][q]=dp[p][q];
			}
			if(cl[i][j]!=-1&&cl[p][q]!=-1)
			dp[p][q]=min(dp[i][j]+1,dp[p][q]);
		}
	}
	if(dp[m][m]!=dp[0][0])cout<<dp[m][m];
	else cout<<-1;
	return 0;
}
