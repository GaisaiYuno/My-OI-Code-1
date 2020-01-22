#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long f[500005],n,d,k,x[500005],s[500005],num[500005];
long long sum=0;
bool check(int g)
{
	long long ans=0;
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		if (g>=d)
		for (int j=1;j<=d+g;j++)
		{
			if (i+j<=sum)
				if (f[i+j]<=f[i]+num[i+j]) f[i+j]=f[i]+num[i+j];
			if (ans<f[i]) ans=f[i];
		}
		else 
		for(int j=d-g;j<=d+g;j++)
		{
			if (i+j>=0&&i+j<=sum)
				if (f[i+j]<=f[i]+num[i+j]) f[i+j]=f[i]+num[i+j];
			if (ans<f[i]) ans=f[i];
		}
	}
	if (ans>=k) return true;
	else return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&s[i]); 
		for (int j=x[i-1];j<x[i];j++)
			num[j]=s[i-1];
		sum+=s[i];
	}
	for (int i=x[n-1];i<=x[n];i++)
		num[i]=s[n];
	if (sum<k) {cout<<-1;return 0;}
	long long lb=1,ub=n+5;
	while (lb+1<ub)
	{
		int mid=(lb+ub)/2;
		if (check(mid)) ub=mid;
		else lb=mid;
	}
	cout<<ub;
	return 0;
}
