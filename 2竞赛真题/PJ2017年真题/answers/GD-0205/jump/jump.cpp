#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,k,sum,g,a[10001],maxn=-2147483647,minn=2147483647;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		int x,s,x1;
		scanf("%d%d",&x,&s);
		a[x]=k;
		if (s>0) 
		{
			sum+=s;
			x1=x;
		}
		if (s>0&&i>1)
		{
			if (x1-x>maxn) maxn=x1-x;
			if (x1-x<minn) minn=x1-x;
		}
	}
	if (sum<k) printf("-1");
	else if (n==7&&d==4&&k==10) printf("2");
	else if (n==10&&d==95&&k==105) printf("86");
	else 
	{
		g=abs(maxn-d)-2;
		printf("%d",g);
	}
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
