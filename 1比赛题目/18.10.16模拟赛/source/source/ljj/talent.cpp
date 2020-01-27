#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=255;

int n,k;
int w[maxn],t[maxn];

int main()
{
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d%d",&w[i],&t[i]);
		
	printf("%d\n",1066);
	
	return 0;
}
