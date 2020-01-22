#include<cstdio>
#include<iostream>
using namespace std;
struct EPZ{
	long long xqml,xqm;
}dz[1001];
long long n,q,i,j,book[1001],t;
long long sqr(long long x)
{
	long long ii,tt=1;
	for (ii=0; ii<x; ii++) tt*=10;
	return tt;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=0; i<n; i++) cin>>book[i];
	for (i=0; i<q; i++) cin>>dz[i].xqml>>dz[i].xqm;
	for (i=0; i<n; i++)
	{
		t=10000001;
		for (j=0; j<q; j++)
		if ((book[j]-dz[i].xqm)%sqr(dz[i].xqml)==0)
		if (dz[i].xqm<t) t=book[j];
		if (t==10000001) cout<<"-1"<<endl;
		else cout<<t<<endl;
	}
	return 0;
}
