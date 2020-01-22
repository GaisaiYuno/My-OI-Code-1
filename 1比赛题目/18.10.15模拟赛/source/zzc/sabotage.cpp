#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

namespace Solution_Sabotage
{

void read(int &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

void read(long long &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

int a[100001];
long double dp[100001];
long double sum=0;
long double maxans;
int n;

bool check(long double x)
{
	maxans=-1e9;
	dp[1]=0;
	for(int i=2;i<n;i++)
	{
		dp[i]=max(dp[i-1]+a[i]-x,a[i]-x);
		maxans=max(dp[i],maxans);
	}
	return sum-n*x-maxans<0;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		sum+=a[i];
	}
	long double l=0,r=1e5;
	while(r-l>1e-5)
	{
		long double mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.3Lf",l);
	return 0;
}

}

int main()
{
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	return Solution_Sabotage::main();
}
