#include<cstdio>
using namespace std;
#define maxlongint 0x7fffffff
int f[500001],queue[500001],x[500001],s[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,l,r,mid,i,j,ans=-1,maxx,minn,head,tail,last;
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&s[i]);
	l=x[1];r=1000000000;
	while(l<=r)
	{
		mid=(l+r)/2;
		maxx=d+mid;
		if(mid<d) minn=d-mid;
		else minn=1;
		for(i=0;i<=n;i++) f[i]=queue[i]=0;
		tail=head=1;last=1;
		for(i=1;i<=n;i++)
		{
			for(j=last;j<i;j++)
			{
				if(x[j]+minn>x[i])
				{
					last=j;
					break;
				}
				if(x[j]+maxx<x[i]) continue;
				if(x[j]+minn<=x[i]&&x[j]+maxx>=x[i]&&f[j]>f[i]) f[i]=f[j];
			}
			f[i]=f[i]+s[i];
		}
		if(f[n]==maxlongint||f[n]<k) l=mid+1;
		else
		{
			ans=mid;
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
