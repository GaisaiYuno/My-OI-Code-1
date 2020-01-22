#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int isbn[1001],dz[1001],cd,fb[1001];
bool book[1001]={false};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,d=1,ans[1001];
	for(int i=1;i<=1001;i++)
	ans[i]=-1;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&isbn[i]);
	}
	sort(isbn+1,isbn+n+1);
	for(int i=1;i<=q;i++)
	{
		d=1;
		scanf("%d",&cd);
		scanf("%d",&dz[i]);
		for(int j=1;j<=n;j++)
		{
			fb[j]=isbn[j];
			int x=1,jw=1;
			while(x<=cd)
			{
				jw*=10;
				x++;
			}
			fb[j]%=jw;
			if(fb[j]==dz[i]&&book[j]==false)
			{
				ans[i]=isbn[j];
				book[j]=true;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
