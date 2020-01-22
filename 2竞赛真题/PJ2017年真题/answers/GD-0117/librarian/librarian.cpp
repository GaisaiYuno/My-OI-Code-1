#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=q; i++)
	{
		int len,x,mod,ans=2147483647;
		bool t=0;
		scanf("%d %d",&len,&x);
		mod=pow(10,len);
		for(int j=1; j<=n; j++)
		 if(a[j]%mod==x) t=1,ans=min(ans,a[j]);
		if(t) printf("%d\n",ans);
		 else printf("-1\n");
	}
	return 0;
}

