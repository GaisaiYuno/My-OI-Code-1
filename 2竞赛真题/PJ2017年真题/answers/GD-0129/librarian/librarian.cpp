#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cwchar>
#include<cwctype>
#include<limits>
using namespace std;
int main()
{   int n=0,q=0,len=0,t=0,a[1009],b[1009],h=0;
	memset(a,0,sizeof(a));
	freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	h=1;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&len,&t);
		b[i]=-1;
		h=1;
		for(int j=1;j<=len;j++)
		h*=10;
		for(int j=1;j<=n;j++)
		{
			if (a[j]%h==t)
			{
			b[i]=a[j];
			break;
		    }
		}
		h=1;
	}
	for(int i=1;i<=q;i++)
	cout<<b[i]<<endl;
	return 0;
}
