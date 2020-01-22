#include <cstdio>
#include <cstring>
#define MAX(A,B) (A>B?A:B)
#define oo 2147483647

int n,d,K,Max;
int Line[500005],f[2005][2005];

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(Line,-1,sizeof(Line));
	memset(f,0,sizeof(f));
	scanf("%d%d%d",&n,&d,&K);
	for(int i=1,a,b; i<=n; i++)
	{
		scanf("%d%d",&a,&b);
		Line[a]=b;
		Max=MAX(Max,a);
	}
	if(d==1)
	{
		for(int j=0; j<=Max-d; j++)
		{
			int now=0,ans=0;
			while(now<=Max)
			{
				now+=j+d;
				if(Line[now]!=-1)
					ans+=Line[now];
				else	break;
				if(ans>=K)
				{
					printf("%d",j);
					return 0;
				}
			}
		}
	}else
	{
		printf("-1");
	}
	return 0;
}
