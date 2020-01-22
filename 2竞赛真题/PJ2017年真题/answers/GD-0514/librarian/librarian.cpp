#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int  n,q;
int a[1011],b[1011],c[1011],ans[1011];
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
		cin>>c[i]>>b[i];
	}
	for (int i=1;i<=q;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int t=10;
			for (int k=1;k<=c[i]-1;k++)t*=10;
			//cout<<a[j]<<' '<<b[i]<<endl;
			if(a[j]%t==b[i])
			{
				//cout<<"yes"<<endl;
				if(ans[i]==0)ans[i]=a[j];
				if(a[j]<ans[i])ans[i]=a[j];
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		if(ans[i]!=0)
		cout<<ans[i]<<endl;
		else cout<<-1<<endl;
	}
}
