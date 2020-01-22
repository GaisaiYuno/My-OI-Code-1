#include<bits/stdc++.h>
using namespace std;
int n,q,i,j;
int p,t,m,k;
long long  a[1010],b[1100],f[1010],c;
long long xp1(long long g,long long h){
	 long long y;  y=h;
	int p=1;  long long r=1;
	   while(y>=10){ y/=10; p++;}
	   for(int i=1;i<=p;i++)r*=10;
	  for(int i=1;i<=p;i++)
	      if(g%r==h)return g;
	   	     else return 10000001;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	    cin>>n>>q;  sizeof(f,10000001,sizeof(f));
	       for(i=1;i<=n;i++)cin>>a[i]; 
	         for(j=1;j<=q;j++)cin>>k>>b[j];  
		for(j=1;j<=q;j++)
		    for(t=2;t<=n;t++){
			     c=min(xp1(a[t],b[j]),xp1(a[t-1],b[j]));
			     f[j]=min(c,f[j]);
			}
		for(j=1;j<=q;j++){
			 if(f[j]!=10000001)cout<<f[j]<<endl;
			  else cout<<"-1"<<endl;
		}
}

