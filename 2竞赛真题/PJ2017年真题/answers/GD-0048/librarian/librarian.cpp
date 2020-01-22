#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,p,a[10005],f[10005],b[10005],ans[10005],c[10005],s;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for (int i=0;i<1005;i++) ans[i]=-1;
	cin>>n>>p;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<p;i++) cin>>c[i]>>f[i];
	for (int i=0;i<p;i++)
	{
		t=1;
		for (int j=0;j<c[i];j++)
		{
			t=t*10;
		}
		b[i]=t;
	}
	for (int i=0;i<p;i++)
	{
		s=0;
		for (int j=0;j<n;j++)
		{
			s=a[j]%b[i];
			if (s==f[i])
			{
				ans[i]=a[j];
				break;
			}
		}
	}
	for (int i=0;i<p;i++) cout<<ans[i]<<endl;
	return 0;
}
