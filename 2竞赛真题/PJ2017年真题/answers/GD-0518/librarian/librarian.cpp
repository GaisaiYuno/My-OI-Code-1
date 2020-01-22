#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,c[1100],r,g;
	cin>>n>>q;
	for(int i=0;i<n;++i)cin>>c[i];
	for(int i=0;i<n;++i)
	for(int j=0;j<n-i;++j)
	{
		if(c[j]>c[j+1])
		{
			int t;
			t=c[j];
			c[j]=c[j+1];
			c[j+1]=t;
		}
	}
	for(int i=0;i<q;++i)
	{
		cin>>g>>r;
		int a=-1,d=1;
		for(int j=0;j<g;++j)d*=10;
		for(int j=0;j<n;++j)
		{
			if(c[j]%d==r)
			{
				a=c[j];
				break;
			}
		}
		cout<<a<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
