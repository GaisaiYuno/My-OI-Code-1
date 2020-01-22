#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[100010],f[100010],l[100010];
bool check(int g,int n)
{
	int lo=1;
	if(g>=10&&g<100) lo=10;
	if(g>=100&&g<1000) lo=100;
	if(g>=1000&&g<10000) lo=1000;
	if(g>=10000&&g<100000) lo=10000;
	if(g>=100000&&g<1000000) lo=100000;
	if(g>=1000000&&g<10000000) lo=1000000;
	while(g>0)
	{
		if(g==n) return true;
		else
		{
			g=g-(lo*(g/lo));	
			lo=lo/10;
		} 
	}
	if(g==n) return true;
	return false;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,b;
	bool flag=false;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{	
	cin>>b;
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=q;i++)
	{
		flag=false;
		for(int j=1;j<=n;j++)
		{
			if(check(a[j],f[i]))
			{
				cout<<a[j]<<endl;
				flag=true;
				break;
			} 
		}
		if(flag==false) cout<<-1<<endl;
	}
	return 0;
}
