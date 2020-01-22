#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int a[1000000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int i,j,n,m,k,x=0,y,z,max,b=1000000000;
	cin>>n>>m>>k;
	for(i=1;i<=n;++i)
	{
		cin>>y;cin>>a[y];
		if(max<y) max=y;
		if(a[y]>0) x+=a[y];
	}
	if(x<k) {cout<<-1;return 0;}
	if(x==k) {z=0;for(i=1;i<=max;++i)
	              {if(a[i]!=0) if(m>abs(z-i)) if(b>m-abs(z-i))b=m-abs(z-i);
				                         else if(m<abs(z-i)&&b>abs(z-i)-m)b=abs(z-i)-m;z=i;}cout<<b;return 0;}
	cout<<2;
	return 0;
}
