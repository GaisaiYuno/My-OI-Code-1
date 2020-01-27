#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register
#define fast static
using namespace std;
typedef long long ll;
int read()
{
	re int x=0,f=1;
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
const int Size=2000005;
fast int n,a[Size],dp[Size];
void init()
{
	n=read();
	for(re int i=1; i<=n; i++)
	{
		a[i]=read();
	}
	int pos=0;
	for(re int i=1; i<=1e6; i++)
	{
		while(pos<n && a[pos+1]<i)	pos++;
		dp[i]=pos;
	}
	sort(a+1,a+1+n);
	unique(a+1,a+1+n);
}
void Baoli()
{
	int ans=0,x;
	for(re int i=2; i<=n; i++)
	{
		for(re int j=1; j<i; j++)
		{
			x=a[j]%a[i];
			if(x>ans)
			{
				ans=x;
			}
		}
	}
	printf("%d",ans);
}
void YumaDuliu()
{
	int ans=0;
	for(re int i=1; i<=n; i++)
	{
		int maxn=a[n]/a[i]+1;
		for(re int k=2; k<=maxn; k++)
		{
			int tmp=a[dp[a[i]*k]]%a[i];
			if(tmp>ans)
			{
				ans=tmp;
			}
		}
	}
	printf("%d",ans);
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	init();
//	Baoli();
	YumaDuliu();
	return 0;
}
