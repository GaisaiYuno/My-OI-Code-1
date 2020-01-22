#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
long long n,d,k,s;
long long far[500010],score[500010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&d);
	scanf("%lld",&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&far[i]);
		scanf("%d",&score[i]);
		s+=score[i];	
	}
	if (s<k) cout<<-1;
	else cout<<2;
	return 0;
}
