#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans=2147483647,n,d,su,num[1000005],dis[1000005],as[1000005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&su);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&dis[i],&num[i]);
	for (int i=0;i<(1<<n);i++)
		{
			long long sum=0;
			int tmp=0,Min=2147483647,Max=0;
			for (int j=1;j<=n;j++)
				if (i&(1<<(j-1)))
					sum+=num[j],as[++tmp]=dis[j];
			if (sum>=su)
				{
					for (int j=1;j<=tmp;j++)
							Min=min(Min,as[j]-as[j-1]),Max=max(Max,as[j]-as[j-1]);
					ans=min(ans,max((int)abs(d-Min),(int)abs(d-Max)));
				}
		}
	if (ans==2147483647)
	cout << -1;
	else 
	cout << ans;
	return 0;
} 
