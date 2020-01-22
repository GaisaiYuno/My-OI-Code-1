#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a,b,c,x[2005][100],w[2000];
long long p[2000],y[2000];
bool k;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; ++i)
	cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=1; i<=n; ++i)
	{
		a=p[i];
		b=0;
		while(a!=0)
		{
			++b;
			x[i][b]=a%10;
			a/=10;
		}
	}
	for(int i=1; i<=q; ++i)
	cin>>w[i]>>y[i];
	for(int i=1; i<=q; ++i)
	{
		k=false;
		for(int j=1; j<=n; ++j)
		{
			c=0;
			for(int l=w[i]; l>=1; --l)
			c=c*10+x[j][l];
			if(c==y[i])
			{
				k=true;
				cout<<p[j]<<endl;
				break;
			}
		}
		if(!k) cout<<-1<<endl;
	}
	return 0;
}
