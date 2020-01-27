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
const int Size=500005;
int cnt,a[Size];
double allavg,sum[Size];
inline void Push(int x)
{
	allavg=((double)allavg*cnt+x)/((double)cnt+1);
	a[++cnt]=x;
	sum[cnt]=sum[cnt-1]+x;
}
bool check(int x)
{
	double avg=(sum[x]+a[cnt])/(x+1);
	return a[x+1]<=avg;
}
inline double Query()
{
//	double maxn=a[sum];
//	double avg=a[sum];
//	for(int i=1; i<=sum; i++)
//	{
//		if(a[i]<=avg)
//		{
//			avg=((double)avg*i+a[i])/((double)i+1);
//		}
//		else
//		{
//			break;
//		}
//	}
//	return maxn-avg;
	double maxn=a[cnt];
	int l=1,r=cnt-1,mid;
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
	return maxn-(sum[l]+a[cnt])/(l+1);
}
int main()
{
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	int Q=read();
	while(Q--)
	{
		int op=read();
		if(op==1)
		{
			Push(read());
		}
		else
		{
			printf("%.10lf\n",Query());
		}
	}
	return 0;
}
/*
6
1 3
2
1 4
2
1 8
2
*/
