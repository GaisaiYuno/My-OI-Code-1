#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,d,k;
int dis[500010],v[500010];
long long f[500010];
bool pd(int g)
{
	int i,j,l1;
	memset(f,128,sizeof(f));
	f[0]=0;
	for (i=0;i<=n-1;++i)
	{
		for (j=i+1;j<=n;++j)
			if(i+dis[j]-dis[i]>=i+d-g) break;
		for (l1=j;l1<=n;++l1)
		{
			if(i+dis[l1]-dis[i]<=i+d+g) f[l1]=max(f[l1],f[i]+v[l1]);
			else break;
		}	
	}
	long long ans=0;
	for (i=0;i<=n;++i) ans=max(ans,f[i]);
	if(ans>=k) return true;
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	int i;
	for (i=1;i<=n;++i)
		scanf("%d%d",&dis[i],&v[i]);
	int l=0,r=max(d-1,n-d)+1,mid=0,flag=0;
	while (l<r)
	{
		mid=(l+r)/2;
		if(pd(mid)) 
		{
			r=mid;
			flag=1;
		}
		else l=mid+1;
	}
	if(flag==0) printf("-1\n");
	else printf("%d\n",l);
}
