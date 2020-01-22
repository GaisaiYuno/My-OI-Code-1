#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int s[1100];
int ten[10];
int main()
{
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	memset (s,0,sizeof (s));
	ten[0]=1;
	for (int i=1; i<=8; i++)
	ten[i]=ten[i-1]*10;
	int n,q;
	cin>>n>>q;
	for (int i=1; i<=n; i++)
	cin>>s[i];
	sort (s+1,s+n+1);
	for (int i=1; i<=q; i++)
	{
		int a,sb;
		cin>>a>>sb;
		int mi=11000000;
		for (int j=1; j<=n; j++)
		if (s[j]%ten[a]==sb) mi=min (mi,s[j]);
		if (mi>10000000) cout<<"-1\n";
		else cout<<mi<<endl;
	}
	return 0;
}

