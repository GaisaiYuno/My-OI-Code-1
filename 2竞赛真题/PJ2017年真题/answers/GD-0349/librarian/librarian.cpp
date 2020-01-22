#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int g[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int n,p,i,j,a[1005],b[1005],len[1005],z;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>p;
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=p;++i)
	 scanf("%d%d",&len[i],&b[i]);
	for(i=1;i<=p;++i)
	 {
	    z=0;
	 	for(j=1;j<=n;++j)
	 	 {
	 	 	if (a[j]%g[len[i]]==b[i]) {z=1; printf("%d\n",a[j]); break;}
	 	 }
	 	if (z==0) cout<<-1<<endl;	
	 }
	return 0;
}
