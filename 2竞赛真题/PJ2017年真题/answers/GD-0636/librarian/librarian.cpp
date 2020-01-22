#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1000;
int n,q;
long int a[maxn],l,b;
long int ans[maxn];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=q;i++)
	{
		ans[i]=10000000;
		scanf("%lld%lld",&l,&b);
		int c=1;
		for(int j=1;j<=l;j++) c=c*10;
		for(int j=1;j<=n;j++)
		{
			int tmp=a[j]%c;
			if(tmp==b) ans[i]=min(a[j],ans[i]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i]==10000000) cout<<"-1"<<endl;
		else printf("%lld \n",ans[i]);
	}
	return 0;
}
