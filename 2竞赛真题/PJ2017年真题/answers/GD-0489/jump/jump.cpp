#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int i,j,m,n,k,d,s[500001],w[500001],sum;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=1;i<=n;i++) 
	{
		cin>>s[i]>>w[i];
		if (w[i]>0) sum+=w[i];
	}
	if (sum<k) cout<<"-1";
	return 0;
}
//sort(,)
//memset(,0,sizeof())
