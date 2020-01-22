#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1005],n,q,l,b,z;
bool t;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&b);
		for (int j=1;j<=n;j++)
		{	
			if (a[j]==b)
			{
				t=true;
				z=j;
				break;
			}
			t=false;
			
			int y=10;
			while (a[j]%y<=b)
			{
				if (b>a[j]) break;
				if (a[j]%y==b)
				{
					t=true;
					z=j;
					break;
				}
				y*=10;
			}
			if (t) break;
		}
		if (t) cout<<a[z]<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
