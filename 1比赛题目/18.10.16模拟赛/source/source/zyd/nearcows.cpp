/*我相信暴力出奇迹*/
/*O(kn)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
#define fast static int
using namespace std;
typedef long long ll;
int read()
{
	re x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=100005;
ll m[Size];
int n,k,c[Size];
int cnt,head[Size];
bool vis[Size];
struct Edge
{
	int v,next;
} w[Size<<1];
void AddEdge(re u,re v)
{
	cnt++;
	w[cnt].v=v;
	w[cnt].next=head[u];
	head[u]=cnt;
}
void init()
{
	n=read();
	k=read();
	for(re i=1; i<n; i++)
	{
		int u=read();
		int v=read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	for(re i=1; i<=n; i++)
	{
		c[i]=read();
	}
}
ll dp[21][Size];
int main()
{
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	init();
	for(re i=1; i<=n; i++)	
	{
		dp[0][i]=dp[1][i]=c[i];
	}
	for(re i=1; i<=n; i++)
	{
		for(re j=head[i]; j; j=w[j].next)
		{
			dp[1][i]+=dp[0][w[j].v];
		}
	}
	for(re i=2; i<=k; i++)
	{
		for(re j=1; j<=n; j++)
		{
			dp[i][j]=dp[i-2][j];
			for(re k=head[j]; k; k=w[k].next)
			{
				int nxt=w[k].v;
				dp[i][j]+=dp[i-1][nxt];
				dp[i][j]-=dp[i-2][j];
			}
		}
	}
	for(re i=1; i<=n; i++)
	{
		printf("%lld\n",dp[k][i]);
	}
	return 0;
}
/*
				dp[i-1][j]+sum{dp[i-1][nxt]}			,i==1
dp[i][j] = {
				dp[i-2][j]+sum{dp[i-1][nxt]-dp[i-2][j]}	,i>1
*/
