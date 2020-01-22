#include<iostream>
#include<cstdio>
using namespace std;
long n,q,i,j,a[1005],b[1005],c[1005],d[1005],e[1005],x,k,l,p,ans;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;++i)
	 cin>>a[i];
	for(i=1;i<=q;i++)
	 cin>>b[i]>>c[i];
	for(i=1;i<=q;i++)
	 d[i]=10,e[i]=10000050;
	for(i=1;i<=q;++i)
	{
		for(j=1;j<=n;j++)
		{
			if(c[i]>a[j]) continue;
			x=a[j];l=0;p=1;ans=0;
			while(l<b[i])
			{
				k=x%10;
				x/=10;
				ans=ans+p*k;
				p*=10;
				l++;
			}
			if(ans==c[i])
			{
				if(a[j]<e[i])d[i]=l,e[i]=a[j];
			}
		}
		if(e[i]!=10000050)
		cout<<e[i]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
