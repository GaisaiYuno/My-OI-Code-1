#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d,k,a[500005],b[500005],ma=0,mi=1000000;
long long zs=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);	
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",&a[i],&b[i]);
		if (b[i]>0) zs+=b[i];
		if (a[i]-a[i-1]>ma) ma=a[i]-a[i-1];
		if (a[i]-a[i-1]<mi) mi=a[i]-a[i-1];
	}
	if (zs<k) cout<<-1; else cout<<max(abs(ma-d),abs(mi-d));
	return 0;
}
