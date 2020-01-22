#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int check(int x,int y)
{
	while(x!=0)
	{
		if(x%10!=y%10) return 0;
		x=x/10;
		y=y/10;
	}
	return 1;
}
int n,m,k,l,a[100005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++) 
	{
		int f=0;
		cin>>l;
		cin>>k;
		for(int i=1;i<=n;i++)
		{
			if(check(k,a[i]))
			{
				f=1;
				cout<<a[i]<<endl;
				break;
			}
		}
		if(!f) cout<<-1<<endl;
	}
	return 0;
}
