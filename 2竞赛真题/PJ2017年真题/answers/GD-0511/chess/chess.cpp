#include<cstdio>
#include<cstring>
using namespace std;
int a[101][101],b[101][101],dp[101][101];
int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
inline int read()
{
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int x=0;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n=read(),m=read(),i,j,k;
	memset(b,0,sizeof(b));
	for(i=1;i<=m;i++)
	{
		int x1=read(),y1=read(),mask=read();
		a[x1][y1]=mask;
		b[x1][y1]=1;
		for(j=1;j<=4;j++)
		if(x1+dx[j]>0&&x1+dx[j]<=n&&y1+dy[j]>0&&y1+dy[j]<=n&&!b[x1+dx[j]][y1+dy[j]])
		{
			a[x1+dx[j]][y1+dy[j]]=2;
			b[x1+dx[j]][y1+dy[j]]=2;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		dp[i][j]=0x7ffffff;
	dp[1][1]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(b[i][j])
		{
			if(b[i][j]==2)
			{
				for(k=1;k<=2;k++)
				if(i+dx[k]>0&&i+dx[k]<=n&&j+dy[k]>0&&j+dy[k]<=n&&b[i+dx[k]][j+dy[k]]!=2&&dp[i+dx[k]][j+dy[k]]+2<dp[i][j])
				{
					dp[i][j]=dp[i+dx[k]][j+dy[k]]+2;
					a[i][j]=a[i+dx[k]][j+dy[k]];
				}
			}
			else
			{
				for(k=1;k<=2;k++)
				if(i+dx[k]>0&&i+dx[k]<=n&&j+dy[k]>0&&j+dy[k]<=n)
				{
					if(a[i][j]!=a[i+dx[k]][j+dy[k]]&&dp[i+dx[k]][j+dy[k]]+1<dp[i][j])
					dp[i][j]=dp[i+dx[k]][j+dy[k]]+1;
					if(a[i][j]==a[i+dx[k]][j+dy[k]]&&dp[i][j]>dp[i+dx[k]][j+dy[k]])
					dp[i][j]=dp[i+dx[k]][j+dy[k]];
				}
			}
		}
	if(dp[n][n]!=0x7ffffff)printf("%d\n",dp[n][n]);
	else printf("-1\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
