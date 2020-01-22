#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,q,was,mod,x,y,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=0;i<q;i++)
	{
		scanf("%d%d",&x,&y);
		mod=1;
		was=0;
		for (int j=1;j<=x;j++) mod*=10;
		for (int j=0;j<n;j++)
		if (a[j]%mod==y) {cout<<a[j]<<endl; was=1; break;}
		if (was==0) cout<<-1<<endl;
	}
	return 0;
}
