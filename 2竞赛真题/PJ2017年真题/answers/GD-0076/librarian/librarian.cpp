#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,q,len;
long long a[1000+10],c,ans=10000001;
bool g;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--)
	{
		cin>>len>>c;
		ans=10000001;
		for(int i=1;i<=n;i++)
		{
			int t=a[i],tmp=0,x=0;
			long long sum=0;
			g=0;
			for(;t>0;t/=10)
			{
				sum=(t%10)*pow(10,tmp++)+sum;
				if(sum==c) g=1;
				if(sum==c||tmp>len) break;
			}
			if(g) ans=min(ans,a[i]);
		}
		if(ans==10000001) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
