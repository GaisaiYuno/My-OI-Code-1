#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,map[500000][2],g=0,now=0,point=0;
unsigned long long all;

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	all=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&map[i][0],&map[i][1]);
		if(map[i][1]>0)all+=map[i][1];
	}
	if(all<k)
	{
		printf("-1");
		return 0;
	}
	else
	for(int i=1;i<=n;i++)
	{
		if(d+g+now<map[i][0])
		{
			g+=map[i][0]-d-g;
			point+=map[i][1];
			now=map[i][0];
		}
		if(point>=k)break;
	}
	printf("%d",g);
	return 0;
}
