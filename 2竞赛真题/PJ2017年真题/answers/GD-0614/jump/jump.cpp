#include<iostream>
#include<cstdio>
using namespace std;
int n,m,l,i,s;
int a[500005],b[500005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&l);
	for (i=0;i<n;i++)
	{
	 scanf("%d%d",&a[i],&b[i]);
	 s+=b[i];
	}
	if (s>l) printf("%d",m-1);
	else printf("%d",-1);
	
	return 0;
}
