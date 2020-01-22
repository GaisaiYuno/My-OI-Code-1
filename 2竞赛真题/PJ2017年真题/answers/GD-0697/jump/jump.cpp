#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;

int main( )
{
 freopen ( "jump.in","r",stdin);
 freopen ( "jump.out","w",stdout);

 int i,n,d,k,a[100001],b[100001],s=0;

 cin>>n>>d>>k; 
 for(i=1;i<=n;i++)
 {
 cin>>a[i]>>b[i];
 if(b[i]>0) s+=b[i];
 }

 if(s<k) cout<<-1;

  return 0;
	
}









