#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;
const long long oo=2147483647;
int n,m,x;
long long ans[1005],a[1005],y;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%lld",&x,&y);
		ans[i]=oo;
		for (int j=1;j<=n;j++)
		{
			int r=a[j],num=0;
			for (int k=1;k<=x;k++)
			{
				num+=pow(10,k-1)*(r%10);
				r/=10;
			}
			if (num==y&&a[j]<ans[i]) ans[i]=a[j];
		}
		if (ans[i]==oo) ans[i]=-1;
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}
