/*我相信暴力出奇迹*/
/*O(n!)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
#define fast static int
using namespace std;
typedef long long ll;
int read()
{
	ll x=0,f=1;
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
const int Size=1005;
struct cow
{
	ll w,t;
} Cow[Size];
ll n,w,sum,ans;
void dfs(int x,int sumw,int sumt)
{
//	printf("%d ",x);
	if(sumw>=w)
	{
		if(sumt*1000/sumw>ans)
		{
			ans=sumt*1000/sumw;
		}
	}
	if(x==n)
	{
//		putchar('\n');
		return;
	}
	for(int i=x+1; i<=n; i++)
	{
		dfs(i,sumw+Cow[i].w,sumt+Cow[i].t);
	}
}
void init()
{
	n=read();
	w=read();
	for(int i=1; i<=n; i++)
	{
		Cow[i].w=read();
		Cow[i].t=read();
		sum+=Cow[i].w;
	}
}
int main()
{
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	init();
	dfs(0,0,0);
	printf("%lld",ans);
	return 0;
}
