#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
long long a[1005];
long long b;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int lenb;
	for(int i=1;i<=q;i++)
	{
		cin>>lenb;
		cin>>b;
		int ans=100000000;
		for(int j=1;j<=n;j++)
		{
			int pd=1;
			int aa=a[j];
			int bb=b;
			while(aa&&bb)
			{
				if((aa%10)!=(bb%10))
				{
					pd=0;
					break;
				}
				aa/=10;
				bb/=10;
				if(!aa&&bb)
				{
					pd=0;
				}
			}
			if(a[j]<ans&&pd==1) ans=a[j];
		}
		if(ans==100000000)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
