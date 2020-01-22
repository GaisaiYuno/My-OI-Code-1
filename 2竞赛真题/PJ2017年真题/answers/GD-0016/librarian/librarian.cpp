#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int s[1010],t[1010];
int num[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=q;i++)
		cin>>num[i]>>t[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=q;i++)
	{
		int pd=0;
		for(int j=1;j<=n;j++)
		{
			int temp=pow(10,num[i]);
			if(s[j]%temp==t[i])
			{
				pd=1;
				cout<<s[j]<<endl;
				break;
			}
		}
		if(pd==0) cout<<-1<<endl;
	}
	return 0;
}
