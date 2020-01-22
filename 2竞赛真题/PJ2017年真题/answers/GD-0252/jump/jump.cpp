#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,l,r,mn,mx,mid,ans,jl[500005],s[500005],dp[10000005];
long long sum;
int check(int g)
{
	mn=max(d-g,1);mx=d+g;
	for(int i=1;i<=n;++i) dp[i]=-1000000001;
	for(int i=0;i<=n;++i)
		for(int j=i+1;j<=n&&jl[j]-jl[i]<=mx;++j)
			if(mn<=jl[j]-jl[i])
				dp[j]=max(dp[j],dp[i]+s[j]);
	for(int i=1;i<=n;++i)
		if(dp[i]>=k)
			return 1;
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&jl[i],&s[i]);
		if(s[i]>0) sum+=s[i];
	}
	if(sum<k)
	{
		printf("-1\n");
		fclose(stdin);fclose(stdout);
		return 0;
	}
	r=jl[n];
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
