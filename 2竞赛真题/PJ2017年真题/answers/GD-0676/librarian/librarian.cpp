#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
long long a[1010],q1[1010],q2[1010];
long long n,q,ans1,ans2;
long long c[10]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
		cin>>q1[i]>>q2[i];
	for(int i=1;i<=q;i++)
	{
		ans1=0;ans2=10000010;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%c[q1[i]]==q2[i])
			{
				ans1=a[j];
				if(ans2>ans1) ans2=ans1;
			}	
		}
		if(ans2==10000010) cout<<-1<<endl;
		else cout<<ans2<<endl;
	}
	return 0;
}
