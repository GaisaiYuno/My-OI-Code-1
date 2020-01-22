#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,k,p,l,a[2001],s;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>p>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>a[i];
		if(a[i]>0) s+=a[i];
	}
	if(s>=k) cout<<p;
	else cout<<-1;
	return 0;
}
