#include<cstdio>
#include<algorithm>
using namespace std;
int n=1,q,a[1005],wei[]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	//for(int i=1;i<=7;i++)printf("%d,",n=n*10);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{
		int w,x;
		scanf("%d%d",&w,&x);
		bool check=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%wei[w]==x)
			{
				printf("%d\n",a[j]);
				check=1;
				break;
			}
		}
		if(!check)printf("-1\n");
	}
}
