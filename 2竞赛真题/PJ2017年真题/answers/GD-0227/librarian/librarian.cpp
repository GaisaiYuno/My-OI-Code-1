#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,q,x,yy,a[10010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=q;++i)
	{
		scanf("%d%d",&x,&yy);
		int flag=1;
		for (int j=1;j<=n;++j)
		{
			int fflag=1,y=yy,xx=a[j];
			while (y)
				if (y%10==xx%10) y/=10,xx/=10;
				else{
					fflag=0;break;
				}
			if (fflag)
			{
				printf("%d\n",a[j]);
				flag=0;break;
			}
		}
		if (flag) printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
