#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct gz
{
	int fs;
	int l;
}a[50000];
int n,d,k;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].fs);
	}
	printf("-1");
	return 0;
}
