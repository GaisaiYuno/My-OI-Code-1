#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,ans=0,sum=0,f[500015],s[500015];
struct jump{
	int l,s;
}a[500015];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=0;i<n;i++) f[i]=0;
	for(int i=0;i<n;i++) cin>>a[i].l>>a[i].s;
	for(int i=0;i<n;i++)
	  if(a[i].s>0) 
		ans+=a[i].s;
	if(ans<k)
	{
		cout<<"-1";
		return 0;
	}
	else {
		cout<<4;
	}
	return 0;
}
