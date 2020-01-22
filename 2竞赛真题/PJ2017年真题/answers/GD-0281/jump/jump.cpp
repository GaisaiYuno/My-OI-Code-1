#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
long long n,d,k,s,x,ans,maxmax;
long long a[500005],b[500005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		s+=b[i];
		if(a[i]-a[i-1]-1>maxmax)maxmax=a[i]-a[i-1]-1;
	}
	if(s<k)
	{
		cout<<-1;
		return 0;
	}
	if(d==1)
	{
		cout<<maxmax;
		return 0;
	}
	return 0;
}
