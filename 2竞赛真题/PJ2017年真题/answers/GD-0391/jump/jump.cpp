#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,m,p,ans,a[500005],b[500005],f[500005];
bool check(int o)
{
	int q=0,s=m-o,t=o+m;
	if (s<=0) s=1;
	for (int i=1;i<=n;i++) f[i]=-900000000;
	f[0]=0;
	for (int i=1;i<=n;i++)
	 {
	 	for (int j=i-1;j>=0;j--)
	 	 if (s<=a[i]-a[j]&&a[i]-a[j]<=t) f[i]=max(f[i],f[j]+b[i]); 
	 	if (f[i]>=ans) return true; 
	 }
	return false;
}
int erfen(int x,int y)
{
	int l=x,r=y,mid=0;
	while (l+1<r) 
	 {
	 	mid=(l+r)/2;
	 	if (check(mid)) r=mid; else l=mid;
	 }
	 return r;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>m>>ans;
	int sum=0;
	for (int i=1;i<=n;i++)
	 {
	 	scanf("%d%d",&a[i],&b[i]);
	 	p=max(p,a[i]);
	 	if (b[i]>0) sum=sum+b[i];
	 }
	if (sum<ans) { cout<<-1; return 0; }
	cout<<erfen(0,p);
	return 0;
}
