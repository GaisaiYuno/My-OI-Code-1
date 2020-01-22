#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
const double eps=1e-4;
int n;
double arr[100005];
double sum[100005];
bool check(double mid)
{
	for(int i=1; i<=n; i++)arr[i]-=mid;
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+arr[i];
	double minn=sum[1];
	double maxn=0;
	for(int i=2; i<n; i++)
	{
		maxn=max(maxn,sum[i]-minn);
		minn=min(minn,sum[i]);
	}
	bool ret;
	if(sum[n]-maxn<=0)ret=1;
	else ret=0;
	for(int i=1; i<=n; i++)arr[i]+=mid;
	return ret;
}
inline int gc()
{
	return getchar();
}
inline int read()
{
	register int x=0;
	register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++)
	{
		arr[i]=read();
	}
	double lb=0,rb=10005;
	while(lb+eps<rb)
	{
		double mid=(lb+rb)/2;
		if(check(mid))rb=mid;
		else lb=mid;
	}
	cout<<fixed<<setprecision(3)<<lb;
}
