#include<cstdio>
#include<cstring>
using namespace std;
int a[510000],b[510000];
int f[510000];
struct node
{
	int id,d;
}tr[510000];int n,d,k;
int abs(int x)
{
	if(x<0) return -x;
	else return x;
}
bool pd(int x)
{
	memset(tr,0,sizeof(tr));
	memset(f,0,sizeof(f));
	int st=1,ed=0;f[0]=0;
	tr[0].id=-1;
	for(int i=1;i<=n;i++)
	{
		while(abs(a[i]-a[tr[st].id]-d)>x&&st<=ed) st++;
		while(abs(a[i]-a[tr[ed].id+1]-d)<=x&&tr[ed].id+1<i)
		{
			int temp=tr[ed].id+1;
			while(tr[ed].d<=f[temp]&&st<=ed) ed--;
			ed++;tr[ed].d=f[temp];tr[ed].id=temp;
		}
		if(st<=ed) f[i]=tr[st].d+b[i];
		if(f[i]>k)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	int l=0,r=1000000000,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(pd(mid)==true)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
