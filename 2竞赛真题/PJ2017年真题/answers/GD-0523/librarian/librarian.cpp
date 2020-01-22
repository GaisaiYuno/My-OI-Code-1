#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[1001],b[1001],c[1001],t[10000001],k[1001],n,q,i,j,r;
int l,minn[1001],s[10000001];
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	cin>>n>>q;
    for(i=1;i<=q;i++)minn[i]=0x7ffffff;
    for(i=1;i<=n;i++)
     cin>>a[i];
    for(i=1;i<=q;i++)
    {
      cin>>b[i]>>c[i];
      t[c[i]]=1;s[c[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
      for(j=8;j>=1;j--)
       if(a[i]*10>=pow(10,j))
       {
	    r=pow(10,j);
       	l=a[i]%r;
      	if(t[l]&&a[i]<minn[s[l]])
      	{
      	  k[s[l]]=1;
      	  minn[s[l]]=a[i];
      	}
       }
    }
    for(i=1;i<=q;i++)
      if(!k[i])cout<<"-1"<<endl;
      else cout<<minn[i]<<endl;
    return 0;
}






