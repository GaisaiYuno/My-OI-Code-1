#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

struct dian
{
	int num;
	int point;
}a[500005];
int n, d, k;

int main ()
{
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	scanf ("%d%d%d", &n, &d, &k);
	int sum=0, Max=-2e9, sum1=0;
	for (int i=1;i<=n;i++)
	{
		scanf ("%d %d", &a[i].num, &a[i].point);
		if (a[i].point>=0) sum+=a[i].point;
		else Max=max(Max,a[i].point);
		sum1+=a[i].point;
	}
	if (sum<k)
	{
		printf ("-1\n");
		return 0;
	}
	if (k==0)
	{
		printf ("0\n");
		return 0;
	}
	if (sum+Max<k)
	{
		int dist=-1, f;
		for (int i=1;i<=n;i++)
		{
			if (a[i].point>=0)
			{
				f=i;
				break;
			}
		}
		dist=a[f].num;
		for (int i=f+1;i<=n;i++)
		{
			if (a[i].point>=0)
			{
				dist=max(dist, a[i].num-a[f].num);
			}
		}
		printf ("%d\n", abs(dist-d));
		return 0;
	}
	printf ("-1\n");
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
