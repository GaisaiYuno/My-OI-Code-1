#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,q,a[100000+5],b,c,w,p,m;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=q;i++)
	{
		cin>>m;c=1;p=0;b=0;w=0;
		cin>>b;
		for (int j=1;j<=m;j++)c*=10;
		for (int j=1;j<=n;j++)
		{
			w=a[j]%c;
			if (w==b) {cout<<a[j]<<endl;p=1;break;}
		}
		if (p==0) cout<<-1<<endl;
	}
	return 0;
}
