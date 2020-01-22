#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1100],b,p;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		int k=1;
		scanf("%d%d",&b,&p);
		while(b--) k*=10;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%k==p)
			{
				printf("%d\n",a[j]);
				break;
			}
			if(j==n) printf("-1\n");
		}
	}
	return 0;
}
