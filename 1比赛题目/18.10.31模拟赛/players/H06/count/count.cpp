/*我相信暴力出奇迹*/
/*O()过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
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
const int Size=300005;
int n,m,Type,a[Size],stmax[Size][21];
void init()
{
	n=read();
	m=read();
	Type=read();
	for(re i=1; i<=n; i++)
	{
		stmax[i][0]=a[i]=read();
	}
	for(re j=1; j<=20; j++)
	{
		for(re i=1<<j; i<=n; i++)
		{
			stmax[i][j]=max(stmax[i][j-1],stmax[i-(1<<(j-1))][j-1]);
		}
	}
}
int Querymax(int l,int r)
{
	int x=log2(r-l+1);
	return max(stmax[l+(1<<x)-1][x],stmax[r][x]);
} 
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	init();
	int l,r;
	ll ans=0;
	while(m--)
	{
		int u=read();
		int v=read();
		if(Type)
		{
			u=(u+ans-1)%n+1;
			v=(v+ans-1)%n+1;
		}
		l=min(u,v);
		r=max(u,v);
		ans=r-l;
		int mina=min(a[l],a[r]);
		for(re i=l; i<=r; i++)
		{
			for(re j=i+2; j<=r; j++)
			{
				if(Querymax(i+1,j-1)<mina)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 2 0
2 1 2
1 1
1 3
*/
