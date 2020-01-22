#include<bits/stdc++.h>
using namespace std;
int n,q,a[1010],i,j,k,x;
char b[10],c[10],f[1010][10];
int ch(int x)
{
	int xx=x,t=0,tt;
	while (xx) xx/=10,t++;
	tt=t;
	for (;x;t--)
	{
		b[t]=(char)(x%10+48);
		x/=10;
	}
	return tt;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++)
	{
		x=ch(a[i]);
		memcpy(f[i],b,sizeof(b));
	}
	for (i=1;i<=q;i++)
	{
		cin>>x>>c;
		bool flag=1;
		for (j=1;j<=n;j++)
		{
			bool flag2=1;
			int l=10,ll,xx=x;
			while (!f[j][l]) l--;
			ll=l;
			if (x>l) continue;
			while (x)
			{
				if (f[j][l]!=c[x-1])
				{
					flag2=0;
					break;
				}
				l--;x--;
			}
			if (flag2)
			{
				for (k=1;k<=ll;k++) cout<<f[j][k];
				flag=0;break;
			}
			x=xx;
		}
		if (flag) cout<<-1;
		cout<<'\n';
	}
}
