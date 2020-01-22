#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,q,k;
int ni[1005],qi;
int check(int qi)
{
	int ans=10000005;
	for (int i=1;i<=n;i++)
	{
		int a,b=1;
		for (int j=1;j<=k;j++) b*=10;
		a=ni[i]%b;
		if (a==qi) ans=min(ans,ni[i]);
	}
	if (ans==10000005) return -1;
	else return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>ni[i];
	for (int i=1;i<=q;i++)
	{
		cin>>k>>qi;
		cout<<check(qi);
	}
	return 0;
}
