#include<cstdio>
#define oo 2000000000
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
int n,d,k,x[500005],s[500005],Max,f[500005];
bool check(int t)
{
	int st=max(d-t,1),en=min(d+t,Max),ans=-oo;
	for (int i=1;i<=n;i++)
	{
		f[i]=-oo;
		for (int j=i-1;j>=0;j--)
			if (x[i]-x[j]>=st&&x[i]-x[j]<=en)
				f[i]=max(f[i],f[j]);
			else
				break;
		if (f[i]!=-oo)f[i]+=s[i];
		ans=max(f[i],ans);
	}
	return ans>=k;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		Max=max(Max,x[i]);
	}
	int lo=-1,hi=1000000005;
	bool OK=false;
	while (lo+1<hi)
	{
		int mid=(lo+hi)/2;
		if (check(mid))
		{
			hi=mid;
			OK=true;
		}
		else
			lo=mid;
	}
	if (OK)
		printf("%d",hi);
	else
		printf("-1");
	return 0;
}
