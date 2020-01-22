#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int i,n,q,mi,p,j,k,b,c,a[10000001],s;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=q;i++)
	{
		cin>>b>>c;s=1;p=0;
		for(j=1;j<=b;j++)s*=10;
		for(j=1;j<=n;j++)if(a[j]%s==c){mi=a[j];p=1;break;}
		if(p==0)cout<<-1<<endl;
		else cout<<mi<<endl;
	}
}
