#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,m,x,ans,b[1005],c[15];
bool tf;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	c[1]=1;
	for(int i=2;i<=11;i++)c[i]=c[i-1]*10;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&m,&x);
		tf=false;
		for(int j=1;j<=n;j++)
		{
			if(b[j]%c[m+1]==x)
			{
				tf=true;
				ans=b[j];
				break;
			}
		}
		if(tf==false)printf("-1\n");
		  else printf("%d\n",ans);
	}
	return 0;
}
