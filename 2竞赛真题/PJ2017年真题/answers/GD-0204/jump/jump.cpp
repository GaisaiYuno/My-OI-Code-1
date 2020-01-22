#include <cstdio>

#define INF 50000000000LL

struct QUEUE
{
	long long s;
	int x;
} q[500005];

long long n,d,k,x[500005],s[500005],f[500005];

long long Check(int g)
{
	int head=1,tail=1;
	long long ret=-INF;
	q[1].x=0;
	q[1].s=0;
	
	for (int i=1;i<=n;i++)
	{
		while (q[head].x<x[i]-(d+g)) head++;
		long long MAX=-INF;
		for (int j=head;j<=tail;j++)
			if (q[j].x<=x[i]-(d-g))
			{
				MAX=q[j].s;
				break;
			}
		f[i]=MAX+s[i];
		int Left=head-1,Right=tail+1;
		while (Left+1<Right)
		{
			int mid=(Left+Right)/2;
			if (q[mid].s<f[i]) Right=mid;
				else Left=mid;
		}
		tail=Right;
		q[tail].s=f[i];
		q[tail].x=x[i];
		if (f[i]>ret) ret=f[i];
	}
	
	return ret;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&d,&k);
	
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&s[i]);
	
	int Left=-1,Right=x[n];
	while (Left+1<Right)
	{
		int mid=(Left+Right)/2;
		if (Check(mid)<k) Left=mid;
			else Right=mid;
	}
	
	if (Check(Right)<k) printf("-1\n");
		else printf("%d\n",Right);
	
	return 0;
}
