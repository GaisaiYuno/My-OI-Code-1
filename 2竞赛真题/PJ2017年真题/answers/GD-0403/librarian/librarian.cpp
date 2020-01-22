#include <iostream>
#include  <cstdio>
#include <algorithm>
using namespace std;
int i,j,k,sh[1001],yu[1001],l[1001],n,m,p1,p2,o[1001];
bool e[1001];
int main()
{
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>sh[i];
	for (i=1;i<=m;i++) cin>>l[i]>>yu[i];
	sort(sh+1,sh+n+1);
	for (i=1;i<=m;i++)
	{
		k=1;p1=10;
		while (k<l[i])
		{
			p1=p1*10;
			k+=1;
		}
		for (j=1;j<=n;j++)
		{
			if (sh[j]%p1==yu[i])
			{
				o[i]=sh[j];
				e[i]=true;
				break;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		if (e[i]) cout<<o[i];
		else cout<<"-1";
		cout<<endl;
	}
	return 0;
}
