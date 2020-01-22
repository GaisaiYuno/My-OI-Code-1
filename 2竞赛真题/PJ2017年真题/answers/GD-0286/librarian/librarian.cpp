#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[1001],ansm,x,xx,y;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		xx=1,ansm=10000001;
		for(j=1;j<=x;j++) xx*=10;
		for(j=1;j<=n;j++)
		if(a[j]%xx==y)
		{
			ansm=a[j];
			break;
		}
		if(ansm==10000001) printf("-1\n");
		else printf("%d\n",ansm);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
