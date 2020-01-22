//´ıÅÄ 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,q;
int a[1000];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	int i;
	for (i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int len,x,tmp,k,j;
	bool bz;
	while (q--)
	{
		scanf("%d %d",&len,&x);
		bz=1;
		for (i=1;i<=n;++i)
		{
			tmp=a[i]-x;
			if (tmp<0)
				continue;
			if (tmp==0)
			{
				printf("%d\n",a[i]);
				bz=0;
				break;
			}
			j=0;
			k=tmp/10;
			while (j<len && tmp-k*10==0)
			{
				tmp=k;
				k=tmp/10;
				++j;
			}
			if (j==len)
			{
				printf("%d\n",a[i]);
				bz=0;
				break;
			}
		}
		if (bz)
			printf("-1\n");
	}
	return 0;
}
