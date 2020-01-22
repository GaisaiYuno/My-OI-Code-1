#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,q,a[1005],f[20]={0,10,100,1000,10000,100000,1000000,10000000},x,y,p,mi;
int main()
{
     freopen("librarian.in","r",stdin);
     freopen("librarian.out","w",stdout);
     cin>>n>>q;
	 for(int i=1;i<=n;i++)
	   cin>>a[i];
	 for(int i=1;i<=q;i++)
     {
	     cin>>x>>y;
	     mi=10000000;p=0;
		 for(int j=1;j<=n;j++)
		 {
		     if(a[j]%f[x]==y) {mi=a[j];p=1;}
		 }
	     if(p==0) cout<<-1<<endl;
	     else cout<<mi<<endl;
	 } 
	 return 0;
}
