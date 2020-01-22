#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

int n,d,k,p[500001],s[500001],f[500001];

bool check(int g)
{
	memset(f,0,sizeof(f));
	for(int i=n;i>=1;--i)
	{
		if(f[i]+s[i]>=k && p[i]<=d+g && p[i]>=d-g)return true;
		for(int j=i-1;j>=1;--j)
		{
			if(p[i]-p[j]<d-g)continue;
			if(p[i]-p[j]>d+g)break;
			f[j]=max(f[j],f[i]+s[i]);
		}
	}
	return false;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",p+i,s+i);
	int ub=p[n]-d+2,lb=0;
	while(ub>lb)
	{
		int mb=(ub+lb)>>1;
		if(check(mb))
			ub=mb;
		else
			lb=mb+1;
	}
	printf("%d\n",check(lb)?lb:-1);
}
