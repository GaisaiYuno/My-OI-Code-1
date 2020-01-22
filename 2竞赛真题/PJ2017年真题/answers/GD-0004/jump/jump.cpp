#include <cstdio>
#include <cstring>

int n,m,k;
struct node{int x,y;};
node a[500010];
int s=0,ans=0,maxx;
int f[500010];
int zuo,you;
void dfs(int x)
{
	for(int i=x+1;i<=n;i++)
	{
		if(a[i].x-a[x].x>=zuo&&a[i].x-a[x].x<=you)
		{
			if(f[x]+a[i].y>f[i])
			{
				f[i]=f[x]+a[i].y;
				if(f[i]>maxx)maxx=f[i];
			}
			dfs(i);
		}
		else if(a[i].x-a[x].x>you)break;
	}
}
int ch(int x)
{
	memset(f,0,sizeof(f));
	maxx=0;
	zuo=m-x;you=m+x;
	dfs(0);
	return maxx;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	a[0].x=0;a[0].y=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		if(a[i].y>0)s+=a[i].y;
	}
	if(s<k)
	{
		printf("-1");
		return 0;
	}
	int l=0,r=a[n].x;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(ch(mid)>=k)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d",ans);
}
