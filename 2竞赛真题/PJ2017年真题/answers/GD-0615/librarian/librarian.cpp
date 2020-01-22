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

int a[1005],n,q,x,l;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&l,&x);
		int m=1,havesolution=0;
		for(int j=1;j<=l;++j)m*=10;
		for(int j=1;j<=n;++j)
			if(a[j]%m==x)
			{
				printf("%d\n",a[j]);
				havesolution=1;
				break;
			}
		if(!havesolution)
			puts("-1");
	}
}
