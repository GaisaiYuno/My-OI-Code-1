#include<iostream>
using namespace std;
int n,m,a[1001],b[1001],c[1001],ma,ans,d[1001];
long long mi;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	cin>>b[i]>>c[i];
	ma=1;
	for(int i = 1;i<=m;i++)
	{
		mi=10000001;
		ans=1;
		for(int j=1;j<=b[i];j++)	
		ans	*=10;
		for(int l=1;l<=n;l++)
		{
			ma=a[l]%ans;
			if(ma-c[i]==0)
				if(mi>a[l])
					mi=a[l];
		}
		if(mi==10000001)mi=-1;
		d[i]=mi;
		
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<endl;
}
