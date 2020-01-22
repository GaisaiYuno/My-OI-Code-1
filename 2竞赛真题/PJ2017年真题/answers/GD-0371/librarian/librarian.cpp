#include<iostream>
#include<cstdio>
using namespace std;
int n,q,i,j,e,b[1001],p[1001],o[1001],h[1001],l=10000001;
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=q;i++)cin>>p[i]>>o[i];
	for(i=1;i<=q;i++)
	{   h[i]=1;
		for(j=1;j<=p[i];j++)
		h[i]*=10;
	}
	for(i=1;i<=q;i++)
	{   l=10000001;
		for(j=1;j<=n;j++)
	{
		e=b[j]-o[i];
		if((e>=0)&&(e%h[i]==0))
		if(b[j]<=l)l=b[j];
	}if(l!=10000001)cout<<l<<endl;
	else cout<<-1<<endl;
	}
    return 0;
}

