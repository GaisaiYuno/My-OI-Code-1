#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int book[1050];
int cifang(int a,int b)
{
	int i,ans=1;
	for (i=1;i<=b;i++) {ans*=a;}
	return ans;
}
int main()
{
	int i,n,q,needlen,need,j,k,p;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) {cin>>book[i];}
	sort(book+1,book+1+n);
	for (i=1;i<=q;i++)
	{
		bool f=false;
		cin>>needlen>>need;
		int mod=cifang(10,needlen);
		for (j=1;j<=n;j++)
		{
			if (book[j]<need) {continue;}
			if (book[j]%mod==need) {cout<<book[j]<<endl;f=true;break;}
		}
		if (!f) {cout<<-1<<endl;}
	}
	return 0;
}
