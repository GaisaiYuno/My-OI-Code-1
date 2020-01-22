#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,i,j,k,o,p,c,a[1005];
int b;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;++i)
	 scanf("%lld",a[i]);
	for(i=1;i<=m;++i)
	{ 
	 o=1;
	 p=10000005;
	 scanf("%lld%lld",&b,&c);
	 for(k=1;k<=b;++k) o*=10;
	 for(j=1;j<=n;++j)
	 {
	  if (a[j]<c) continue;
	  if (a[j]%o==c) p=min(p,a[j]);
     }
     if (p!=10000005) cout<<p<<endl; else cout<<"-1"<<endl;
    }
    return 0;
}
