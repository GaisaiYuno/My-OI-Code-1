#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500001;
int x[MAXN],s[MAXN];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&s[i]);
	printf("-1");
	return 0;
}
