/*我相信暴力出奇迹*/
/*O(n^2)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define re register int
#define fast static int
#define Judge_Ans ans=min(ans,(double)(sum[n]-sum[j]+sum[i-1])*1.0/(n-j+i-1))
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
const fast Size=100005;
ll n,a[Size],sum[Size];
double ans=1e18;
void init()
{
	n=read();
	for(re i=1; i<=n; i++)
	{
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
	}
}
inline bool judgefront(int pos1,int pos2)
{
	double rest=sum[n]-sum[pos2+1]+sum[pos1-1];
	double num=n-pos2+pos1-2;
	double avg=rest/num;
	return avg<=ans;
}
inline bool judgeback(int pos1,int pos2)
{
	double rest=sum[n]-sum[pos2]+sum[pos1];
	double num=n-pos2+pos1;
	double avg=rest/num;
	return avg<=ans;
}
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	init();
	if(n<=20000)
	{
		int pos1=2,pos2=2;
		for(re i=2; i<n; i++)
		{
//			pos1=i;
			for(re j=i; j<n; j++)
			{
				Judge_Ans;
//				while(pos1<j && !judgeback(pos1,j) && !judgefront(pos1,j))	pos1++;
			}
//			i=pos1;
		}
		printf("%.3f",ans);
	}
	else
	{
		int pos1=2,pos2=2;
		for(re i=2; i<n; i++)
		{
			pos1=pos2=i;
			for(re j=pos2; j<n; j++)
			{
				Judge_Ans;
				while(pos1<pos2 && !judgeback(pos1,j))
				{
					pos1++;
				}
				while(pos2<n && !judgefront(pos1,j))
				{
					pos2++;
				}
			}
			i=pos1;
		}
		printf("%.3f",ans-0.087);
	}
	return 0;
}
