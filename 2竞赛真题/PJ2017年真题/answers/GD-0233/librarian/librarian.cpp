#include<cstdio>
using namespace std;
int n,m;
int a[1001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,d,k=1;
		scanf("%d%d",&x,&d);
		for(int i=1;i<=x;i++)k*=10;
		int ans=999999999;
		for(int i=1;i<=n;i++)
		{
			int t=a[i]%k;
			if(t==d)
			{
				if(ans>a[i])ans=a[i];
			}
		}
		if(ans==999999999)printf("-1\n");
		else printf("%d\n",ans);
	}
}
