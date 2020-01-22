#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,q,l,s,x,min;
	int a[1005];
	int b[1005];
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=q;++i) 
	{
		x=1; min=-1;
		cin>>l>>s;
		for (int j=1;j<=l;++j) x*=10;
		for (int j=1;j<=n;++j) 
		if (((a[j]%x==s)&&(a[j]<min))||((a[j]%x==s)&&(min==-1))) 
		min=a[j];
		b[i]=min;
	}
	for (int i=1;i<=q;++i) cout<<b[i]<<endl;
	fclose(stdin);
	fclose(stdout);
}
