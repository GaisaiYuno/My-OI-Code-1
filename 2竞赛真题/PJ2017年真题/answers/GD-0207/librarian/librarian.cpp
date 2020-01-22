#include<bits/stdc++.h>
using namespace std;
int n,q,book[1001],i,tmp,t,j,tt;
bool flag;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>book[i];
	sort(book+1,book+n+1);
	for(i=1;i<=q;i++)
	{
		cin>>t>>tmp;
		tt=1;
		flag=false;
		for(j=1;j<=t;j++)tt*=10;
		for(j=1;j<=n;j++)
		{
			if(book[j]%tt==tmp)
			{
				cout<<book[j]<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)cout<<"-1"<<endl;
	}
	return 0;
}
