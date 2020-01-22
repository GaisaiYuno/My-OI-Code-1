#include <iostream>
#include <cstdio>

#define MaxN 500+5
#define InpF "jump.in"
#define OutF "jump.out"

using namespace std;
int main()
{

	freopen(InpF,"r",stdin);
	freopen(OutF,"w",stdout);

	int f[MaxN][MaxN];
	int o[MaxN][2];

	int n,d,k;
	scanf("%d%d%d",&n,&d,&k);

	int sum=0;
	int cnt=0;
	int laP=-1;

	int Max=-2147483647,Min=2147483647;

	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&o[i][0],&o[i][1]);
		if(o[i][1]>0)
		{
			sum+=o[i][1];
			if(cnt!=0)
			{
				if(o[i][0]-laP>Max) Max=o[i][0]-laP;
				if(o[i][0]-laP<Min) Min=o[i][0]-laP;
			}
			laP=o[i][0];
		}
	}
	if(sum<k)
	{
		printf("-1\n");
		return 0;
	}
	if(sum=k)
	{
		int g1=Max-d;
		int g2=d-Min;
		if(g1>g2)
		{
			printf("%d\n",g1);
			return 0;
		}
		else
		{
			printf("%d\n",g2);
			return 0;
		}
	}
}	
