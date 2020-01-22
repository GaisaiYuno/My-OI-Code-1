#include<bits/stdc++.h>
using namespace std;
int n,p,bk[1010],rd[1010],dv,nm,q;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",&bk[i]);
	sort(bk+1,bk+n+1);
	for(int i=1;i<=p;i++)
	{
		nm=1;dv=1;
		scanf("%d%d",&q,&rd[i]);
		for(int j=1;j<=q;j++)dv*=10;
		while((bk[nm]%dv)!=rd[i]&&nm<=n+1)nm++;
		if(nm<=n)cout<<bk[nm]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
