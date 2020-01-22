#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct fg{
	long long w,f;
}dp[550000];
long long n,d,k,maxn,minn,l,r,ans,mid;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>dp[i].w>>dp[i].f;
		if(dp[i].f>0) maxn+=dp[i].f;
		if(minn>=k&&l==0) l=i;
		if(maxn>=k&&r==0) r=i;
	}
	if(maxn<k)
	{
		cout<<-1;
		return 0;
	}
	int sum=0;
	for(int i=1;i<=l;i++)
	sum+=dp[i].f;
	if(sum<k)
	{
		for(int i=1;i<=r;i++)
		ans=max(ans,dp[i].w-dp[i-1].w);
	}
	else 
	for(int i=1;i<=l;i++)
	ans=max(dp[i].w-dp[i-1].w,ans);
	cout<<ans-d+1;
	return 0;
}
