#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#define re register ll
using namespace std;
typedef long long ll;
ll read()
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
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	re n=read(),sn=n,ans=0;
	n=n*n;
	re p,sp;
	for(re i=1; i<=sn; i++)
	{
		p=n-i*i;
		sp=sqrt(p);
		if(sp*sp==p)
		{
			ans++;
		}
	}
	printf("%lld",ans<<2);
	return 0;
}
