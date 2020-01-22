#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
long long k,s;
int a[10000+5],d,n,x[10000+5],q,p;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
		if(a[i]<0)p++;
		if(a[i]>0)s+=a[i];
	}
	if(s<k){cout<<-1;exit(0);}
	cout<<d-p;
}
