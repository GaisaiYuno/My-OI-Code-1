#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1001;
int k,have[MAXN],ans[MAXN],n,q,x,y,i,j;
bool NOP;
bool cup(const int &a,const int &b)
{
	return a<b;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(have,0,sizeof(have));
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&have[i]);
	sort(have+1,have+n+1,cup);
	for(j=1;j<=n;j++)
		scanf("%d%d",&k,&ans[j]);
	for(i=1;i<=q;i++)
	{
		NOP=1;
		for(j=1;j<=n;j++)
		{
			if(ans[i]==have[j])
			{
				printf("%d\n",have[j]);
				break;
			}
			else
			{
				if(have[j]<ans[i])
					continue;
				x=have[j];
				y=ans[i];
				while(y>0)
				{
					int ab=x%10;
					int av=y%10;
					x/=10;
					y/=10;
					if(ab!=av)
					{
						NOP=0;
						break;
					}
				}
				if(NOP)
				{
					printf("%d\n",have[j]);
					break;
				}
			}
		}
		if(!NOP)
			printf("-1\n");
	}
	return 0;
}
