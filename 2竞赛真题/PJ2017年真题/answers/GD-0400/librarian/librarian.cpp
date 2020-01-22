//[暴力保过护符] 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main() 
{
	int a1[1111],a[1111],n,p,max,z,l,bj;
	freopen("librarian.in","r",stdin); freopen("librarian.out","w",stdout);
	cin>>n>>p;
	for (int i=1;i<=n;i++) cin>>a1[i];
	for (int i=1;i<=n;i++) 
	 { 
	  max=10000001;
	  for (int j=1;j<=n;j++)
	    if (a1[j]<max) {z=max; max=a1[j]; a1[j]=z;}	
	  a[i]=max;    
     } 
    for (int i=1;i<=p;i++)
     {
     	cin>>l>>z;
     	max=1; bj=0;
     	for (int j=1;j<=l;j++) max*=10;
     	for (int j=1;j<=n;j++) 
     	  if (a[j]%max==z) {cout<<a[j]<<endl; bj=1; break;}
     	if (bj==0) cout<<-1<<endl;
     } 
     fclose(stdin); fclose(stdout);
}
