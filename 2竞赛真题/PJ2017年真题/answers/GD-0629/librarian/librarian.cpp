#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,q;
int book[10010];
struct read
{
	int xq;
	int l;
}a[10010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",&book[i]);
	for(int i=1;i<=q;i++)
	scanf("%d%d",&a[i].l,&a[i].xq);
		sort(book+1,book+n+1);
	for(int i=1;i<=q;i++)
	{
		bool b=false;
		for(int j=1;j<=n;j++)
		if(book[j]%(int)pow(10,a[i].l)==a[i].xq)
		{
			printf("%d\n",book[j]);
			b=true;
			break;
		}
		if(b==false)printf("-1\n");
	}
	return 0;
}
