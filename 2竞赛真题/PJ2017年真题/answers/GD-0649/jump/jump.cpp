#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
long long n,d,k,i,j,sum=0,xi=100000001,da=-100000001,t,dlh;
struct EPZ{
	long long x,s;
}a[500111];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=0; i<n; i++){
		cin>>a[i].x>>a[i].s;
		if (a[i].s>0) sum+=a[i].s;
	}
	if (sum<k){cout<<"-1"; return 0;}
	for(i=0; i<n; i++)
	for (j=0; j<n; j++)
	{
		t=abs(a[i].s-a[j].s);
		if (t<xi) xi=t;
		if (t>da) da=t;
	}
	dlh=abs(da-d);
	if (abs(d-xi)>dlh) dlh=abs(d-xi);
	if (sum=k) {cout<<dlh; return 0;}
	cout<<dlh;
	return 0;
}
