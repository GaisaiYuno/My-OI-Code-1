#include<iostream>
#include<cstdio>
using namespace std;
int a[1100],b[1100],c[1100],l[1100];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,j,s,min;cin>>n>>q;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=q;++i)cin>>b[i]>>c[i];
	for(i=1;i<=q;++i)
	{
		for(j=1;j<=q;++j)l[j]=2147483647;
		s=1;
		for(j=1;j<=b[i];++j)s=s*10;
		for(j=1;j<=q;++j)
		if(a[j]%s==c[i])l[j]=a[j];
		min=2147483647;
		for(j=1;j<=q;++j)if(l[j]<min)min=l[j];
		if(min==2147483647)cout<<"-1";
		else cout<<min;
		if(i==q)s=0;else cout<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
