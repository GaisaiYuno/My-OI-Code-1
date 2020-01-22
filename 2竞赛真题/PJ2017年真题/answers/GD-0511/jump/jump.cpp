#include<cstdio>
#include<algorithm>
using namespace std;
struct ch1
{
	int x,w;
};
int n,d,p,from1,to1,sum1=0,mid1;
ch1 a[500001];
bool p1=0,k1=0;
inline bool check(int k,int c,int b)
{
	if(p1)
	{
		return false;
	}
	else
	{
		int c1=c+from1,c2=c+to1;
		if(a[b+1].x-c>to1)
		{
			p1=1;
			return false;
		}
		for(int i=b+1;i<=n;i++)
		if(!k1&&a[i].x-c>=from1&&a[i].x-c<=to1)
		{
			sum1+=a[i].w;
			if(sum1>=p)
			{
				k1=1;
				return true;
			}
			else
			check(k+1,a[i].x,i);
			sum1-=a[i].w;
		}
		else
		if(k1)
		return true;
		return false;
	}
}
bool cmp(ch1 a,ch1 b)
{
	return a.x<b.x;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int i,sums=0,max1=-0x7fffffff;
	scanf("%d%d%d",&n,&d,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].w);
		if(a[i].w>0)
		sums+=a[i].w;
		if(a[i].w>max1)max1=a[i].w;
	}
	if(sums<p)printf("-1\n");
	else
	{
		sort(a+1,a+n+1,cmp);
		int l=0,r=max1-d;
		while(l<=r)
		{
			mid1=(l+r)/2;
			p1=0,k1=0;
			if(mid1<d)
			from1=d-mid1,to1=d+mid1;
			else
			from1=1,to1=mid1+d;
			if(check(1,0,0))
			r=mid1-1;
			else
			l=mid1+1;
		}
		printf("%d\n",l);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
