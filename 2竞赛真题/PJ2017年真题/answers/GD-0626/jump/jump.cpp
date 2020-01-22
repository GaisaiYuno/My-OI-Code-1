#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long ans=0;
int n,d,k;
struct node{int x,s;}a[500010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1; i<=n; i++) 
	{
		scanf("%d %d",&a[i].x,&a[i].s);
		if( a[i].s>0 ) ans+=a[i].s;
	}
	long long kk=k;
	if( ans<kk ) printf("-1");
	else printf("2");
	return 0;
}

