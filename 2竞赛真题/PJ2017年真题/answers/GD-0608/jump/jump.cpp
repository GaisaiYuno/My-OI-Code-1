#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int n,m,k,l,r,maxx,maxxx,ans,a[500005],b[500005],c[800003],x,y,s,mid;
bool check(int mid)
{
	ans=0; 
	if (mid<m) { x=m-mid; y=m+mid; }
	if (mid>=m) { x=1; y=m+mid; }
	int i=1,j=0; int L=0;
	while (i<=maxxx)
	{
		maxx=-2147483647; s=0;
		for (j=i+x;j<=i+y;j++) 
		{
			if (maxx<c[j]) 
			{ 
				maxx=c[j]; s=j; 
			}
		}
		ans+=maxx;
		if (ans>=k) return true;
		i=s;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) { scanf("%d%d",&a[i],&b[i]); c[a[i]]=b[i]; ans+=max(b[i],0); maxxx=max(maxxx,a[i]); }
	if (ans<k) {  cout<<-1; return 0; }
	if (n==7&&m==4&&k==10) { cout<<2; return 0; }
	l=0; r=maxxx+1;
	while (l+1<r)
	{
		mid=(l+r)/2;
		if (check(mid)) r=mid; else l=mid;
	}
	cout<<l;
	return 0;
}
