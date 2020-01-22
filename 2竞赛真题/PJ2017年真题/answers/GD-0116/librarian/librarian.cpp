#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int  a[10001],b,c,d,ans,tot;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>b>>c;tot=0;
	for(int i=1;i<=b;i++) 
	{
		cin>>a[i];	tot=max(tot,a[i]);
	}
	for(int i=1;i<=c;i++)
	{
		int x,y;ans=tot+1;
		int k=1;
		cin>>x>>y;
		for(int j=1;j<=x;j++) k*=10;
		for(int j=1;j<=b;j++)
		{
			int q=a[j]%k;
			if(q==y) ans=min(ans,a[j]);
		}
		if(ans==tot+1) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
