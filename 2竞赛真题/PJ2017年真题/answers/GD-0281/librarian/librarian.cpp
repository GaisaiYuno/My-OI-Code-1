#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
int n,q,len,bh;
long long a[1005],b[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<q;i++)
	{
		cin>>len>>bh;
		for(int j=0;j<n;j++)
		{
			long long j1=bh,j2=a[j];
			bool f=true;
			for(;j1>0;j1/=10,j2/=10)
			{
				if(j1%10!=j2%10)
				{
					f=false;
					break;
				}
			}
			if(f==true)
			{
				b[i]=a[j];
				break;
			}
		}
		if(b[i]==0)b[i]=-1;
	}
	for(int i=0;i<q;i++)cout<<b[i]<<endl;
	return 0;
}
