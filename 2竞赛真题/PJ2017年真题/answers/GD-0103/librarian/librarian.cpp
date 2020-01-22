#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n,m,have[1001],want[1000];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&have[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d %d",&k,&want[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int minn=10000000;
		for(int j=1;j<=n;j++)
		{
			bool ok=true;
			int a=want[i];
			int b=have[j];
			while(a>0)
			{
				if(a%10!=b%10)
				{
					ok=false;
					break;
				}
				a/=10;
				b/=10;
			}
			if(ok)
			{
				minn=min(minn,have[j]);
		}
		}
		if(minn==10000000)
		printf("-1\n");
		else
		printf("%d\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
