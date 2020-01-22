#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,num[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)	scanf("%d",&num[i]);
	sort(num+1,num+1+n);
	for(int i=1;i<=q;i++)
	{
		int len,need,mod;
		scanf("%d%d",&len,&need);
		mod=1;
		while(len--)mod*=10;
		int p;
		p=-1;
		for(int j=1;j<=n;j++)
			if(num[j]%mod==need)
			{
				p=j;
				break;
			}
		if(p==-1)	printf("-1");
		else printf("%d",num[p]);
		printf("\n");
	}
	return 0;
}
