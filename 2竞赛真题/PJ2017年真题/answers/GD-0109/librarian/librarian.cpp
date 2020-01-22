#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
long long a[3000],b,n,p,o,l=1;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=p;i++)
	{
		bool t=false;
		scanf("%lld%lld",&o,&b);
		for (int j=1;j<=o;j++)
		{
			l=l*10;
		}
		for (int j=1;j<=n;j++)
		{
			if(a[j]%l==b) 
			{
				cout<<a[j]<<endl;
				t=true;
				break;
			}
		}
		if(!t) cout<<-1<<endl;
		l=1;
	}
	return 0;
}
