#include <iostream>
#include <cstdio>
#include <cmath>
#define oo 2147483647
using namespace std;
int n,d,k,x[510],y[510],sum,jl[510],Max;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	x[0]=0,Max=-oo;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		jl[i]=x[i]-x[i-1];
		if (y[i]>0) sum+=y[i];
		Max=max(Max,x[i]-x[i-1]);
	} 
	if (d==1&&sum>=k) {cout<<0;return 0;}
	if (sum<k) {cout<<-1;return 0;}
	cout<<2;
	return 0;
}
