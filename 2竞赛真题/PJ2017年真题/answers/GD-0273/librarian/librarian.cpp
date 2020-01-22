#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	int a[1006],b[1006],c[1006];
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	for (int i=1;i<=q;i++)
	{
	  int k;
	  c[i]=1;
	  cin>>k>>b[i];
	  for (int j=1;j<=k;j++)
	    c[i]=c[i]*10;
    }
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++)
	{
		int j,t=0;
	  for (j=1;j<=n;j++)
		if ((a[j]-b[i])%c[i]==0) {t=1;break;}
	  if (t) cout<<a[j]<<endl;
	  else cout<<-1<<endl;
	}
	return 0;
}
