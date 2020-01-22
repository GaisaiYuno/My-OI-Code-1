#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b,c,n,t[10000001],q,y,x,i;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++)
	{
		cin>>a;
		t[a]=a;b=10;c=a;
		while (b<a)
		{
			c=a%b;
			if (t[c]!=0) t[c]=min(a,t[c]);else t[c]=a;
			b*=10;
		}
	}
	for (i=1;i<=q;i++)
	{
		cin>>y>>x;
		if (t[x]==0) cout<<-1<<endl;
		 else cout<<t[x]<<endl;
	}
	return 0;
}
