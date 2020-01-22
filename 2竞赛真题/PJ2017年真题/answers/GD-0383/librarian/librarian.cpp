#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,q,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{
		int s,q2=1,w,f=1;
		cin>>s>>w;
		for(int j=1;j<=s;j++)
		  q2=q2*10;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%q2==w)
			{
				cout<<a[j]<<endl;
				f=0;
				break;
			}
		}
		if(f==1)
		  cout<<-1<<endl;
	}
	return 0;
}
