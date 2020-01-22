#include<iostream>
#include<cstdio>
using namespace std;
int n,q,book[1001],len,need,ans;
int cut[10]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>book[i];
	for (int i=1;i<=q;i++) 
	{
		ans=2147483647;
		cin>>len>>need;
		for (int j=1;j<=n;j++)
			if (book[j]%cut[len]==need) ans=min(ans,book[j]);
		if (ans==2147483647) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

