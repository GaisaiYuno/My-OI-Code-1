#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,len,need,t,l,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d",&len,&need);
	 	t=1;l=0;
		for (int j=1;j<=len;j++)
	 	 t*=10;
	 	for (int j=1;j<=n;j++)
	 	 if (a[j]%t==need) {printf("%d\n",a[j]);l=1;break;}
	 	if (l==0) printf("-1\n");
	 }
	return 0;
}
