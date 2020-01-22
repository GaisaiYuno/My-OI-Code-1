#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int i,j,k,l=10,m,n,q,p,b,c,a[1001],maxl,aa;
string h;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) 
	{
		k=1;cin>>h;
		for (j=h.size()-1;j>=0;j--) {a[i]+=(h[j]-48)*k;k*=10;}
	}
	for (i=1;i<=q;i++) 
	{
		maxl=100000001;
		cin>>b>>c;
		for (j=1;j<=n;j++)
		{
			if (a[j]>=c)
			{
				l=10;for (k=1;k<=b-1;k++) l=l*10;aa=a[j]%l;
				if ( (aa==c)&&(a[j]<maxl) ) maxl=a[j];
			}
		}
		if (maxl==100000001) cout<<"-1"<<endl;
		else cout<<maxl<<endl;
	}
	return 0;
}
//sort(,)
//memset(,0,sizeof())
