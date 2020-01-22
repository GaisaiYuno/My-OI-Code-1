#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,d,k,a1,a2,h=0;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a1>>a2;
		if(a2>0)h+=a2;
	}
	if(h<k){cout<<-1;return 0;}
	if(h==k)cout<<n-d;
	cout<<0;
	return 0;
	
}
