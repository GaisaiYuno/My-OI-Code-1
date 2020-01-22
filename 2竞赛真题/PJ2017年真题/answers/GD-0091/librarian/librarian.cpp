#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	long a[1000],b[1000],c[1000];
	int j,i,n,q;
    cin>>n>>q;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=q;i++)
	{ 
	 int x,ii; 
	 cin>>x;c[i]=1;
	 for(ii=1;ii<=x;ii++) c[i]*=10;
	 cin>>b[i];
	 
	 }
    for(j=1;j<=q;j++)
   {
    int bj=0,bb=0;;
    for(i=1;i<=n;i++)
    {
        if(a[i]%c[j]==b[j]) {bj=1;
		if(bb!=0) 
		{if(a[bb]>a[i]) bb=i; }
	else bb=i;
		}
    }
	if(bj==1) cout<<a[bb]<<endl;
    if(bj==0) cout<<"-1"<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
