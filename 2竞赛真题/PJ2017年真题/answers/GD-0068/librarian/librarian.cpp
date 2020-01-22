#include <iostream>
#include <cstdio>
#include <algorithm>

#define MaxN 1000+5

#define InpF "librarian.in"
#define OutF "librarian.out"

using namespace std;

int requestCode[8]={1,10,100,1000,10000,100000,1000000,10000000};

int main()
{

	freopen(InpF,"r",stdin);
	freopen(OutF,"w",stdout);

	int Lib[MaxN];

	int n,q;
	scanf("%d%d",&n,&q);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&Lib[i]);
	}
	sort(Lib+1,Lib+n+1);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);

		bool check=false;

		for(int j=1;j<=n;j++)
		{
			if(Lib[j]%requestCode[x]==y)
			{
				printf("%d\n",Lib[j]);
				check=true;
				break;
			}
		}

		if(!check)
		{
			printf("-1\n");
		}
	}
	return 0;
}
