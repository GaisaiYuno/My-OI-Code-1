#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1010],n,q,m,c,y,p;
int main()
{
	freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=q;i++)
	{
		cin>>m>>c;y=1;p=0;
		for (int j=1;j<=m;j++) y=y*10;
		for (int j=1;j<=n;j++)
		{
			if (a[j]%y==c) 
			{
				cout<<a[j]<<endl;
				p=1;
				break;
			}
		}
		if(p==0) cout<<-1<<endl;
	}
	return 0;
}
