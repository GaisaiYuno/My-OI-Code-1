#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

namespace Solution_Talent
{

template<typename type>
void read(type &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

long double tmp;
//first:w, second:t
pair <int,int> cow[250];
long double dp[6505];
int n,w;

struct cmp
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)const
	{
		return (a.second-a.first*tmp)>(b.second-b.first*tmp);
	}
};

struct cmp2
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)const
	{
		return (a.second-a.first*tmp)/a.first>(b.second-b.first*tmp)/b.first;
	}
};

bool check(long double mid)
{
	//memset(dp,0,sizeof(dp));
	for(int i=0;i<6500;i++)dp[i]=-1e8;
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=6500;j>0;j--)
		{
			if(j>=cow[i].first)
			dp[j]=max(dp[j],dp[j-cow[i].first]+cow[i].second-cow[i].first*mid);
		}
	}
	for(int i=w;i<=6500;i++)
	{
		if(dp[i]>=1e-7)
		{
		//	cout<<mid<<" "<<i<<" "<<dp[i]<<endl;
			return true;
		}
	}
	return false;
}

int main()
{
	read(n);read(w);
	for(int i=0;i<n;i++)
	{
		int w,t;
		read(w);read(t);
		cow[i]=make_pair(w,t);
	}
	long double l=0,r=1e5;
	while(r-l>1e-5)
	{
		long double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<int(r*1000);
	return 0;
}

}

int main()
{
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	return Solution_Talent::main();
}
