#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,i,a[100005],k,pos,zw,j,t;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1; i<=q; i++)
	{
		t=0;
		cin>>k>>pos;
		zw=1;
		for (j=1; j<=k; j++) zw*=10;
		for (j=1; j<=n; j++)
		if (a[j]%zw==pos) {t=1;cout<<a[j]<<endl;break;}
		if (t==0) cout<<-1<<endl;
	}
	return 0;
}
