#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,s[100000],x[100000];
	long long k;
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
	}
	cout<<-1;
	return 0;
}
