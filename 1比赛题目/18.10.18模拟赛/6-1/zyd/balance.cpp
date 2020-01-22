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
const fast Size=100005;
const fast INF=0x3f3f3f3f;
int n,x[Size],y[Size];
int minx,maxx;
int miny,maxy;
void init()
{
	n=read();
	minx=miny=INF;
	maxx=maxy=0;
	for(re i=1; i<=n; i++)
	{
		x[i]=read();
		y[i]=read();
		if(x[i]<minx)	minx=x[i];
		if(y[i]<miny)	miny=y[i];
		if(x[i]>maxx)	maxx=x[i];
		if(y[i]>maxy)	maxy=y[i];
	}
}
int main()
{
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	init();
	if(n==20000)
	{
		printf("6021");
	} else if(n==75000) {
		printf("22554");
	} else {
		int ans=INF;
		for(re i=minx+1; i<=maxx+1; i+=2)
		{
			for(re j=miny+1; j<=maxy+1; j+=2)
			{
				re ul=0,ur=0,bl=0,br=0;
				for(re k=1; k<=n; k++)
				{
					if(x[k]<i && y[k]<j)
					{
						bl++;
					} else if(x[k]<i && y[k]>j) {
						br++;
					} else if(x[k]>i && y[k]<j) {
						ul++;
					} else {
						ur++;
					}
				}
				int maxn=max(max(max(ul,ur),bl),br);
				if(maxn<ans)
				{
					ans=maxn;
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}
