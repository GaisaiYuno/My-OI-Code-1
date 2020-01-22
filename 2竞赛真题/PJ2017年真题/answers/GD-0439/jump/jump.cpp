#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,k,a[500010],v[500010],f[500010],l,r,mid,sum;
bool check(int x)
{
	memset(f,0,sizeof f);
	if (x<d)
	{
		if (a[1]<d-x||a[1]>d+x) return 0;
		f[1]=v[1];
		for (int i=2;i<=n;i++)
			for (int j=1;j<i;j++)
				if (a[i]-a[j]>=d-x&&a[i]-a[j]<=d+x) f[i]=max(f[i],f[j]+v[i]);
		if (f[n]<k) return 0;
		return 1;
	}
	if (a[1]>d+x) return 0;
	f[1]=v[1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<i;j++)
			if (a[i]-a[j]<=x+d) f[i]=max(f[i],f[j]+v[i]);
	if (f[n]<k) return 0;
	return 1;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&v[i]),sum+=max(0,v[i]);
	if (sum<k){printf("-1");return 0;}
	if (d==1)
	{
		l=0,r=a[n]-a[1];
		while (l<r)
		{
			mid=(l+r)>>1;
			if (check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d",l);
		return 0;
	}
	for (int i=1;i<=min(n,a[n]-a[1]);i++)if (check(i)){printf("%d",i);return 0;}
	l=min(n,a[n]-a[1]),r=a[n]-a[1];
	while (l<r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
