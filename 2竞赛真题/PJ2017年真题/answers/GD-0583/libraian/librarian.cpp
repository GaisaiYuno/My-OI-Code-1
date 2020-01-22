#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[1001];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,x,y;
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=q;++i)
	{
		cin>>x>>y;int z=1,m=-1;
		for(int j=1;j<=x;++j) z*=10;
		for(int j=1;j<=n;++j)
		{
			if(a[j]%z==y&&m!=-1) m=min(m,a[j]);
			else if(a[j]%z==y&&m==-1) m=a[j];			
		}
		cout<<m<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
