#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,book[1001],need,x,k;
bool flag;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&book[i]);
	}
	sort(book+1,book+n+1);
	for (int i=1;i<=n;i++)
	{
		k=1;
		flag=true;
		cin>>x>>need;
		for (int j=1;j<=x;j++) k*=10;
		for (int j=1;j<=n;j++)
		{
			if (book[j]%k==need && flag)
			{
				cout<<book[j]<<endl;
				flag=false;
			}
		}
		if (flag)
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
