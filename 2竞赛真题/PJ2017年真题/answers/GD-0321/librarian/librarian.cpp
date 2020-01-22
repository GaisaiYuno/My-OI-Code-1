#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005],b[1005],c[1005],n,q,v;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=n;i++)
	{
       cin>>v>>c[i];
       int g=1;
       for(int j=1;j<=v;j++)
       g=g*10;
       b[i]=g;
       
    }
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{
		bool t=false;
		int an=0;
		for(int j=1;j<=n;j++)
		{
			int u=a[j]%b[i];
			if(u==c[i])
			{
				t=true;
				an=j;
				break;
			}
		}
		if(t)cout<<a[an]<<endl;
		else cout<<"-1"<<endl;
	}
return 0;
}
