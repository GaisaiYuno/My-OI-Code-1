#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int p,n,q,a[1010],m,b;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	
	for(int i=1;i<=q;i++)
	{
		p=1;
		scanf("%d%d",&m,&b);
		for(int j=1;j<=m;j++)
		p*=10;
		bool f=0;
		for(int j=1;j<=n;j++)
		if((a[j]-b)%p==0)
		{cout<<a[j]<<endl;f=1;break;}
		if(f==0)cout<<-1<<endl;
	}
	return 0;
}
