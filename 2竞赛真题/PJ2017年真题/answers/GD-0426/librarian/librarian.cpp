#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int n,q,sum=1,c[10];
long long a[1010],b[1010];
int main()
{
	freopen("librarian","r",stdin);
	freopen("librarian","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		cin>>b[i];
		cin>>c[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{
		sum=1;
		int t=0;
		for(int k=1;k<=b[i];k++) sum*=10;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%sum==c[i])
			{
				cout<<a[j]<<endl;
				t=1;
				break;
			}
		}
		if(t==0) cout<<-1<<endl;
	}
	
	return 0;
}
