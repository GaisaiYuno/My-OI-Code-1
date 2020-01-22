#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
long long a[1000+5],s[1000+5],c[1000+5];
int n,m,b,p;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int j=1;j<=1000;j++)
	  c[j]=1;
	for(int j=1;j<=m;j++)
	{
		cin>>b>>s[j];
		for(int i=1;i<=b;i++)
		  c[j]*=10;
	}
	for(int j=1;j<=m;j++)
	{
		p=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%c[j]==s[j]){cout<<a[i]<<endl;p=1;break;}
		}
		if(p==0)cout<<-1<<endl;
	}
	return 0;
}
