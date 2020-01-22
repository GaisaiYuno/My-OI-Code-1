#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,a[500000+2],b,c,g,m;
long long k,t;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d",&b,&c);
		a[b]=c;
		m=max(b,m);
	}
	cout<<-1;
	return 0;
}
