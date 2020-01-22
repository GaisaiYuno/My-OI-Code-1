#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int n,q;
	int a[1001],b[1001][2],c[1001],m,d;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(c,-1,sizeof(c));
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=q;j++)
	{
		cin>>b[j][1]>>b[j][2];
	}
	sort(a+1,a+n+1);
	for(int l=1;l<=q;l++)
	{
		for(int o=1;o<=n;o++)
		{
			m=0;
			d=pow(10,b[l][1]);
			if(d>(a[o]*10))
			continue;
			else if(d<(a[o]*10))
			{
				m=a[o]%d;
				if(m==b[l][2])
				{
					c[l]=a[o];
					break;
				}
			}
		}
	}
	for(int k=1;k<=q;k++)
	{
		cout<<c[k]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
