/*我相信暴力出奇迹*/
/*O(n^2)过百万 暴力碾标算*/
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
const fast Size=100005;
fast f[Size],s[Size],d[Size];
int main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	re n=read();
	re b=read();
	re maxn=0;
	for(re i=1; i<=n; i++)
	{
		f[i]=read();
		if(f[i]>maxn)	maxn=f[i];
	}
	for(re i=1; i<=b; i++)
	{
		s[i]=read();
		d[i]=read();
	}
	for(re i=1; i<=b; i++)
	{
		if(d[i]==1)
		{
			if(maxn>s[i])
			{
				puts("0");
			}
			else
			{
				puts("1");
			}
		}
		else
		{
			re pos=1;
			while(pos<n)
			{
				re ri=pos+d[i];
				for(re j=ri; j>pos; j--)
				{
					if(f[j]<=s[i])
					{
						ri=j;
						break;
					}
				}
				if(ri==pos+d[i] && f[ri]>s[i])
				{
					break;
				}
				pos=ri;
			}
			if(pos<n)
			{
				puts("0");
			}
			else
			{
				puts("1");
			}
		}
	}
	return 0;
}
