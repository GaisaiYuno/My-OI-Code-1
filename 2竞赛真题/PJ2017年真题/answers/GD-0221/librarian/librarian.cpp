#include<bits/stdc++.h>
using namespace std;
int n,q,i;
int a[10000];
int b[10000][2];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=q;i++) cin>>b[i][1]>>b[i][2];
	for(i=1;i<=q;i++)
	{
		int m=-1,z=0;
		for(int j=1;j<=n;j++)
		{
			int r=1;
			for(int k=1;k<=b[i][1];k++) r=r*10;
			if(a[j]%r==b[i][2])
			{
				if(z==0)
				{
					m=a[j];z=1;
				}else{
					if(m>a[j]) m=a[j];
				}
			}
		}
		cout<<m<<endl;
	}
}
