#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
long change(long n,long m)
{
	long ans=0,t=1,i,check=1;
	for(int i=1;i<=n;i++)
	check*=10;
	return m%check;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	long n,q,i,a[5000],b[5000],ans,tmp,tmp2,num,j;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<q;i++)
	{
		ans=10000001;
		cin>>tmp>>tmp2;
		for(int j=0;j<n;j++)
		{
			num=change(tmp,a[j]);
			if(num==tmp2) ans=min(ans,a[j]);
		}
		if(ans!=10000001) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
