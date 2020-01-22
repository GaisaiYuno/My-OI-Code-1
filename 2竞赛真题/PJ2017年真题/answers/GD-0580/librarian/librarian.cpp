#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
long long n,m,i,q,r,ad,kk,p,o1,p2,o,w,p1,a[10000],b[10000],k;

int main()
{
    freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q,&r);
	    ad=2147483647;p1=0;
		for (k=1;k<=n;k++)
		{
			p=1;kk=a[k];w=r;p2=0;
			while(1!=0)
			{
			  o1=kk%10;
			  kk=kk/10;
			  o=w%10;
		      w=w/10;
			  if (o1!=o) {
			  break;}else p2++;
			  if (p2==q){
			  p=0;break;}
			  
			}
			if (p==0) if(a[k]<ad) {
			ad=a[k];p1=1;}
		}
		if (p1==1)b[i]=ad;else b[i]=-1;
	}
	for (i=1;i<=m;i++)
	printf("%lld\n",b[i]);
	return 0;
}
