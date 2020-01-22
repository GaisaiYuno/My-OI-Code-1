#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[210000];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,p;scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=p;i++)
	{
		int x,y,l=-1;scanf("%d%d",&x,&y);
		int t=1;
		for(int i=1;i<=x;i++)t=t*10;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%t==y)
			{
				l=a[j];break;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
