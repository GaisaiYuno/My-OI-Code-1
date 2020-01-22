#include<iostream>
#include<fstream>
using namespace std;
int n,q,a[1005],len,b,t,smaller;
bool k;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;;
	for(int i=1;i<=n;i++)
	{cin>>a[i];}
	for(int i=1;i<=q;i++)
	{
		cin>>len>>b;
		t=1;
		for(int j=1;j<=len;j++)
		t*=10;smaller=10000005;k=0;
		for(int j=1;j<=n;j++)
		if(a[j]%t==b)
		{k=1;smaller=min(smaller,a[j]);}
		if(k==1)cout<<smaller<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
