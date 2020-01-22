#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,k,x[500005],s[500005],f[500005];
bool check(int kk)
{
	for (int i=0;i<=n;i++) f[i]=0;
	int ans=0;
	for (int i=1;i<=n;i++)
	  {
	  	f[i]=-1;
	  	for (int j=i-1;j>=0;j--)
	  	  if (x[i]-x[j]>=d-kk&&x[i]-x[j]<=d+kk&&f[j]!=-1) f[i]=max(f[i],f[j]+s[i]);
	  	ans=max(ans,f[i]);
	  	if (ans>=k) return true;
	  }
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	x[0]=0;s[0]=0;
	for (int i=1;i<=n;i++)
	  {
	  	scanf("%d%d",&x[i],&s[i]);
	  }
	int left=-1,right=1000000005;
	while (left+1<right)
	  {
	  	int mid=(left+right)/2;
	  	if (check(mid)) right=mid;else left=mid; 
	  }
	if (right>1000000000) cout<<-1;else cout<<right;
	return 0;
}
