#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int oo=2147483646;
int n,q,a[1005],b[1005],l[1005];
int mypow(int x)
{
	int ans=1;
	for (int i=1;i<x;i++) ans*=10;
	return ans;
}
void check(int x,int len)
{
	int ans=oo;
	for (int i=1;i<=n;i++)
	if (a[i]%mypow(len+1) ==x)
	{	
		ans=min(ans,a[i]);
	}
	if (ans!=oo) cout<<ans<<endl;
	else cout<<-1<<endl;
	return ;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=q;i++)
	{
		cin>>l[i]>>b[i];
	}
	for (int i=1;i<=q;i++) check(b[i],l[i]);
	return 0;
}

