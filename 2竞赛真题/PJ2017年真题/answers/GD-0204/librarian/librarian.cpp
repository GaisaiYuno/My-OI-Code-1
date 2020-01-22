#include <cstdio>
#define INF 2000000000

int n,q,a[1005],b[1005],len;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&len,&b[i]);
		
		int p=1;
		while (len--) p*=10;
		
		int ans=INF;
		for (int j=1;j<=n;j++)
			if (a[j]%p==b[i]&&a[j]<ans) ans=a[j];
		
		if (ans==INF) printf("-1\n");
			else printf("%d\n",ans);
	}
	
	return 0;
}
