#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1005];
int b[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		int x,y,k=1;
		bool c=0;
		scanf("%d%d",&x,&y);
		for(int j=1;j<=x;j++)k*=10;
		for(int j=1;j<=n;j++)if(a[j]%k==y)
		{
			c=1;
			printf("%d\n",a[j]);
			break;
		}
		if(!c)printf("-1\n");
	}
	return 0;
}
