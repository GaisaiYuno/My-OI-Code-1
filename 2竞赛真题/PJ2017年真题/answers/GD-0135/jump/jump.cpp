#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int n,d;
int a[500010],v[500010];
long long f[500010],k,sum;
bool check(int x)
{
	memset(f,0,sizeof(f));
	for(int i=0;i<=n;i++)
	{
		if(f[i]!=0||i==0)for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]>=d-x&&a[j]-a[i]<=d+x)
			{
				f[j]=max(f[j],f[i]+(long long)v[j]);
				//printf("%d\n",f[j]);
				if(f[j]>=k)return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long l=0,r=0,mid;
	scanf("%d%d%lld",&n,&d,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i],&v[i]);
		if(v[i]>0)sum+=v[i];
		r=max((long long)a[i]-(long long)a[i-1],r);
	}
	if(sum<k)
	{
		printf("-1");
		return 0;
	}
	r*=2;
	//printf("%d\n",check(2));
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;else l=mid+1;
		//cout<<l<<ends<<r<<endl;
	}
	printf("%lld",l);
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2

2 1 10
1 5
3 5
*/
