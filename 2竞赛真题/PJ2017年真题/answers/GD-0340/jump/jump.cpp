#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,d,k,t1,t2,s,a,r,ans=-1000;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	cin>>s>>a; t1=s; t2=a;
	for (int i=2; i<=n; i++)
	{
		cin>>s>>a;
		if (a>0) r+=a;
		if (abs(t2+a-k)<abs(t2-k)) 
		{
			ans=max(ans,s-t1);
			t2=t2+a;
			t1=s;
		} 
	}
	if (r<k) cout<<-1; else
	{
		if (ans>k) cout<<ans-k; else cout<<k;
	}
	return 0;
}
