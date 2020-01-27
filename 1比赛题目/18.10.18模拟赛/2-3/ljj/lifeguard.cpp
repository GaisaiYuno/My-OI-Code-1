#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100005;

struct data{
	int x,y;
} a[maxn];

int n,k,ans;

int main()
{
	freopen("lifeguard.in","r",stdin);
	freopen("lifeguard.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	ans=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		ans=max(ans,a[i].y-a[i].x);
	}
	printf("%d\n",ans);
	return 0;
}
