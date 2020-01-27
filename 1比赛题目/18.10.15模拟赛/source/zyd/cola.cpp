/*我相信暴力出奇迹*/
/*O(tnm)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
#define fast static int
using namespace std;
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
const fast Maxt=1000005;
fast dp0[Maxt][31];
fast dp1[Maxt][31];
struct Edge
{
	int v,next;
};
static Edge w[205];
int cnt,head[31];
void AddEdge(re u,re v)
{
	w[++cnt].v=v;
	w[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	re n=read();
	re m=read();
	for(re i=1; i<=m; ++i)
	{
		re u=read();
		re v=read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	re t=read();
	dp0[0][1]=dp0[1][1]=dp1[1][1]=1;
	for(re i=head[1]; i; i=w[i].next)
	{
		dp0[1][w[i].v]=1;
	}
	for(re i=2; i<=t; ++i)
	{
		for(re j=1; j<=n; j++)
		{
			for(re k=head[j]; k; k=w[w[k].next].next)
			{
				dp0[i][j]=dp0[i][j]+dp0[i-1][w[k].v]+dp0[i-1][w[w[k].next].v];
			}
			dp0[i][j]=(dp0[i][j]+dp0[i-1][j])%2017,dp1[i][j]=(dp1[i][j]+dp0[i-1][j])%2017;
		}
	}
	register int ans=0;
	for(re i=1; i<=t; i+=5,ans=ans%2017)
	{
		for(re j=1; j<=n; j+=3)
		{
			ans=ans+dp1[i][j]+dp1[i][j+1]+dp1[i][j+2];
		}
		if(i+1>t)	break;
		for(re j=1; j<=n; j+=3)
		{
			ans=ans+dp1[i+1][j]+dp1[i+1][j+1]+dp1[i+1][j+2];
		}
		if(i+2>t)	break;
		for(re j=1; j<=n; j+=3)
		{
			ans=ans+dp1[i+2][j]+dp1[i+2][j+1]+dp1[i+2][j+2];
		}
		if(i+3>t)	break;
		for(re j=1; j<=n; j+=3)
		{
			ans=ans+dp1[i+3][j]+dp1[i+3][j+1]+dp1[i+3][j+2];
		}
		if(i+4>t)	break;
		for(re j=1; j<=n; j+=3)
		{
			ans=ans+dp1[i+4][j]+dp1[i+4][j+1]+dp1[i+4][j+2];
		}
	}
	for(re i=1; i<=n; i+=3)
	{
		ans=ans+dp0[t][i]+dp0[t][i+1]+dp0[t][i+2];
	}
	printf("%d",ans%2017);
	return 0;
}
