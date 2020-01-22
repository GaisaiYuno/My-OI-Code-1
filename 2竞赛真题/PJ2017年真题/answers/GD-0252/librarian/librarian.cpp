#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,q,l,s,k,b,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&l,&s);b=0;k=1;
		for(int j=1;j<=l;++j) k*=10;
		for(int j=1;j<=n;++j)
		{
			if(a[j]%k==s)
			{
				printf("%d\n",a[j]);
				b=1;
				break;
			}
		}
		if(!b) printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
