#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[1001],x,b[1001],c[1001],ans[1001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>b[i];
		c[i]=1;
		ans[i]=-1;
		for(int j=1;j<=x;j++)
			c[i]*=10;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>0;i--)
		for(int j=1;j<=m;j++)
		{
			int p=a[i]%c[j];
			if(p==b[j]) ans[j]=a[i];
		}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
