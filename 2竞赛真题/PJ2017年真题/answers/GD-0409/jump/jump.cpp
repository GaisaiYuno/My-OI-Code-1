#include<bits/stdc++.h>
using namespace std;
int n,d,k,ans=INT_MAX,i,j,l,r;
struct hh
{
	int dist,num;
}a[500010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for (i=1;i<=n;i++) scanf("%d %d",&a[i].dist,&a[i].num);
	r=max(a[n].dist-d,d);
	while (l<r)
	{
		int mid=(l+r+1)>>1,f[500010],tot=INT_MIN;
		memset(f,-127,sizeof(f));
		f[0]=0;
		for (i=1;i<=n;i++)
		{
			for (j=i-1;j>=0&&a[i].dist-a[j].dist<=d+mid;j--)
				if (a[i].dist-a[j].dist>=d-mid)
				{
					f[i]=max(f[i],f[j]+a[i].num);
					tot=max(tot,f[i]);
				}
		}
		if (tot<k) l=mid;
		else 
		{
			ans=min(ans,mid);r=mid-1;
		}
	}
	printf("%d",(ans==INT_MAX?-1:ans));
}
