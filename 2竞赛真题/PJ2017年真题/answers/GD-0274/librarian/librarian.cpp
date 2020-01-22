#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int g[1000+10];
int n,q,u,o,t1,t2,jsq;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
    for (int i=1;i<=n;i++)
	{
		cin>>g[i];
	}
	sort(g+1,g+n+1);
	for (int i=1;i<=q;i++)
	{
		cin>>u>>o;
		jsq=0;
		for (int j=1;j<=n;j++)
		{
			t1=o;
			t2=g[j];
			for (int z=1;z<=u;z++)
			{
				if (t1%10==t2%10)
				{
					t1=t1/10;
					t2=t2/10;
				}
			}
			if (t1==0)
			{
				jsq++;
				cout<<g[j]<<endl;
				break;
			}
		}
		if (jsq==0)
		{
			cout<<"-1"<<endl;
		}
	}	
	return 0;
}
