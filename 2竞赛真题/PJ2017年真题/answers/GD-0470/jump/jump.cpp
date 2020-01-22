#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,d,k;
struct node
{
	int d,score;
}q[500010];
long long sum[500010];
int f[500010];

int max(int x,int y)
{
	return x>y?x:y;
}

bool dp(int x)
{
	memset(f,0,sizeof(f));
	int head=1,tail;
	if (x<d)
	{
		for (int i=1;i<=n;i++)
		{
			tail=i;
			while (q[head].d+d+x<q[i].d) head++;
			while (q[tail].d+d-x>q[i].d && tail>head) tail--;
			if (tail==1 && q[1].d<d-x) return false;
			for (int j=head;j<=tail;j++)
				f[i]=max(max(f[j],f[j]+q[i].score),f[i]);
		}
		if (f[n]>k) return true;
		return false;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			while (q[head].d+d+x<q[i].d) head++;
			for (int j=head;j<=i;j++)
				f[i]=max(max(f[j],f[j]+q[i].score),f[i]);
		}
		if (f[n]>k) return true;
		return false;
	}
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	int last=0,l=2147483647,r=2147483647;
	for (int i=1;i<=n;i++)
	{
		int x,c;
		scanf("%d %d",&x,&c);
		if (x-last<l) l=x-last;
		sum[i]=max(sum[i-1],sum[i-1]+c);
		q[i].d=x;q[i].score=c;
		last=x;r=x;
	}
	if (sum[n]<k) 
	{
		printf("-1");
		return 0;
	}
	while (l!=r)
	{
		int mid=(l+r)/2;
		if (dp(mid)) r=mid;
		else l=mid+1;
	}
	if (dp(l)) printf("%d",l);
	else printf("%d",l+1);
	return 0;
}
