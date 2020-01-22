#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int a[1010],b[1010],c[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,j;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++)
	{
		cin>>b[i];
		cin>>c[i];
	}
	for(int i=1;i<=q;i++)
	{
		for(j=1;j<=n;j++)
		{
			int h=a[j],p=0,s=1,z=1;
			while(s<=b[i])
			{
				p+=h%10*z;
				z=z*10;
				s++;
				h=h/10;
			}
			if(p==c[i])
			{
				cout<<a[j]<<endl;
				break;
			}
		}
		if(j==n+1)
		{
			cout<<-1<<endl;
		}
	}
	return 0;	
}
