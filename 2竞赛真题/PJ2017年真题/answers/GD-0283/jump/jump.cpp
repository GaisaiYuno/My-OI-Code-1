#include <cstdio>
#include <iostream>
#include <cstring>
#define oo 200000000LL;
using namespace std;
int Max,Min,n,d,k,t,dis[500005],f[500005],score[500005];
int MAX(int a,int b){return a>b?a:b;}
int MIN(int a,int b){return a>b?b:a;}

bool check(int x)
{
	int ans=-oo;
	int Ld=MAX(d-x,1),Rd=d+x;
	for (int i=1;i<=n;i++)
	{
		f[i]=-oo;
		for (int j=0;j<i;j++)
			if (Ld<=dis[i]-dis[j]&&dis[i]-dis[j]<=Rd)
			{
				f[i]=MAX(f[j]+score[i],f[i]);
			}
		ans=MAX(ans,f[i]);
	}
	return (ans>=k);
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	Min=oo;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&dis[i],&score[i]);
		Max=MAX(Max,dis[i]-dis[i-1]);
		Min=MIN(Min,dis[i]-dis[i-1]);
		if (score[i]>0) t+=score[i];
	}
	if (t<k)
	{
		cout<<-1<<endl;
		return 0;
	}
	int left=0,right;
	if (Min<d&&d<Max)
		right=MAX(d-Min,Max-d); else
	if (d<Min)
		right=Max-d; else
	if (d>Max) right=d-Min;
	while (left+1<right)
	{
		int mid=(left+right)/2;
		if (check(mid)) right=mid;
			else left=mid;
	}
	if (check(0)) right=0;
	cout<<right<<endl;
	return 0;
}
