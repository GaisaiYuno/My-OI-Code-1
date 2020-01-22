#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,q,a,b,_min,mod;
int s[1100],m[10]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++) scanf("%d",&s[i]);
	for(int i=1; i<=q; i++)
	{
		scanf("%d %d",&a,&b);
		mod=m[a]; _min=10000010;
		for(int j=1; j<=n; j++) if( s[j]%mod==b ) _min=min(_min,s[j]);
		if( _min!=10000010 ) printf("%d\n",_min);
		else printf("-1\n");
	}
	return 0;
}

