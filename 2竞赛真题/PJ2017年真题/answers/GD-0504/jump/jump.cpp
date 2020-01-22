#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
int n,d,k;
struct Info
{
	int x,s;
} a[500001];
long long f[500001];
int que[500001],head,tail;
bool ok(int);
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	int i;
	int l=0;
	for (i=1;i<=n;++i)
	{
		scanf("%d %d",&a[i].x,&a[i].s);
		l=max(l,a[i].x-a[i-1].x);
	}
	l-=d;
	int r=a[n].x,mid,res=INT_MAX;
	while (l<=r)
	{
		mid=l+r>>1;
		if (ok(mid))
			r=(res=mid)-1;
		else
			l=mid+1;
	}
	if (res==INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",res);
	return 0;
}
bool ok(int g)
{
	memset(f,128,sizeof f);
	f[0]=0;
	head=0;
	tail=-1;
	int i,j=0;
	long long MAX=INT_MIN,NINF=f[1];
	for (i=1;i<=n;++i)
	{
		while (j<i && a[j].x+d-g<=a[i].x)
		{
			if (f[j]==NINF)
			{
				while (j<i && f[j]==NINF)
					++j;
				if (j>=i || a[j].x+d-g>a[i].x)
					break;
			}
			while (head<=tail && f[que[tail]]<=f[j])
				--tail;
			que[++tail]=j;
			++j;
		}
		while (head<=tail && a[que[head]].x+d+g<a[i].x)
			++head;
		if (head<=tail)
			f[i]=f[que[head]]+a[i].s;
		MAX=max(MAX,f[i]);
	}
	return MAX>=k;
}
