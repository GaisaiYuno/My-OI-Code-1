#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>s
using namespace std;
long n,p,a[1001],b[1001],q,c[1001],ans;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=p;i++)
	{
		cin>>b[i]>>c[i];
	}
	for(int i=1;i<=p;i++)
	{
		q=1;
		for(int j=1;j<=b[i];j++)
		{
			q*=10;
		}
		ans=10000001;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%q==c[i]&&ans>a[j])
			{
				ans=a[j];
			}
		}
		if(ans==10000001) cout<<-1<<endl;
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
