#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,m,a[1005],b,ans,sum,c;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	 {
	 	cin>>c>>b;
	 	sum=1; ans=999999999;
	 	for (int j=1;j<=c;j++)
	 	 sum=sum*10;
	 	for (int j=1;j<=n;j++)
	 	 if (a[j]%sum==b) 
	 	  ans=min(ans,a[j]);
	 	if (ans!=999999999) cout<<ans; else cout<<-1;
	 	cout<<endl;
	 }
	return 0;
}
