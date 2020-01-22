#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a,s,z,x,w[10000007];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d\n",&n,&q);
	for (int i=1;i<=10000000;i++) w[i]=20000000;
	for (int i=1;i<=n;i++)
	{
		scanf("%d\n",&a);
		s=10;
		while (s<=a)
		s*=10;
		while (s!=1)
		{
			int o=a%s;
			w[o]=min(w[o],a);
			s/=10;
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d\n",&z,&x);
		if (w[x]==20000000)
		{
			printf("%d\n",-1);
		} else printf("%d\n",w[x]);
	}
	return 0;
}
