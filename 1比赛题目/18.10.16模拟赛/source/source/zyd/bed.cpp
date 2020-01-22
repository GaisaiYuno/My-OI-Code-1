/*我相信暴力出奇迹*/
/*O(nlogn)过百万 暴力碾标算*/
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
int n,k,a[Size];
fast stmax[Size][21];
fast stmin[Size][21];
int Querymax(int l,int r)
{
	int x=log2(r-l+1);
	return max(stmax[l+(1<<x)-1][x],stmax[r][x]);
}
int Querymin(int l,int r)
{
	int x=log2(r-l+1);
	return min(stmin[l+(1<<x)-1][x],stmin[r][x]);
}
void init()
{
	n=read();
	k=read();
	for(re i=1; i<=n; i++)
	{
		a[i]=read();
	}
	for(re i=1; i<=n; i++)
	{
		stmax[i][0]=stmin[i][0]=a[i];
	}
	for(re j=1; j<=20; j++)
	{
		for(re i=1<<j; i<=n; i++)
		{
			stmax[i][j]=max(stmax[i][j-1],stmax[i-(1<<(j-1))][j-1]);
			stmin[i][j]=min(stmin[i][j-1],stmin[i-(1<<(j-1))][j-1]);
		}
	}
}
bool check(int len)
{
	for(re l=1,r=len; r<=n; l++,r++)
	{
		if(Querymax(l,r)-Querymin(l,r)<=k)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	init();
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if(check(l+1))
	{
		printf("%d",l+1);
	}
	else if(check(l))
	{
		printf("%d",l);
	}
	else
	{
		printf("%d",l-1);
	}
	return 0;
}
