#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[1005];
int main()
{
	int n,q,tl,t,tt;
	bool a;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=q;i++)
	{
		cin>>tl>>t;tt=1;a=false;
		for(int j=1;j<=tl;j++)
		tt*=10;
		for(int j=1;j<=n;j++)
		if(t==s[j]%tt){cout<<s[j];a=true;break;}
		if(!a)cout<<-1;
		if(i<q)cout<<endl;
	}
	return 0;
}
