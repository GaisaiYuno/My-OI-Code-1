#include<iostream>
#include<cstdio>
using namespace std;
bool k[10005]={false};
int q,n,ans[10000]={1000005},num[10000],need[10000],u,book[10000];
int cf(int o)
{
	int p=1;
	for(int i=1;i<=o;i++)
	p*=10;
	return p;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	scanf("%d",&book[i]);
	for(int i=1;i<=q;i++)
	{
		cin>>u>>need[i];
		num[i]=cf(u);
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=1000005;
		for(int j=1;j<=q;j++)
		{
			if(book[j]%num[i]==need[i])
			{
				if(ans[i]>book[j])
				{
					ans[i]=book[j];
					k[i]=true;
				}
			}
		}
		if(k[i])
		printf("%d\n",ans[i]);
		else
		printf("-1\n");
	}
	return 0;
}
