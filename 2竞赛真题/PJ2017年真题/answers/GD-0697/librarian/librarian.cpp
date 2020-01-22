#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;

bool comp(int x,int y)
{
	 return x<y;			
}


int main( )
{
 freopen ( "librarian.in","r",stdin);
 freopen ( "librarian.out","w",stdout);

 long int b[1001],bn[1001],r[1001],rn[1001],num[100],i,j,p,q,m,n,k,l,g,s;
 string u;
 bool f=true,sc=false;
 cin>>n>>q;
 for(i=1;i<=n;i++) cin>>b[i];
 sort(b+1,b+n+1,comp);
 for(i=1;i<=n;i++) 
 {if(b[i]<10) bn[i]=1;                       if((b[i]<100)&&(b[i]>=10)) bn[i]=2;
  if((b[i]<1000)&&(b[i]>=100))bn[i]=3;       if((b[i]<10000)&&(b[i]>=1000))bn[i]=4;
  if((b[i]<100000)&&(b[i]>=10000))bn[i]=5;   if((b[i]<1000000)&&(b[i]>=100000))bn[i]=6;
  if((b[i]<10000000)&&(b[i]>=1000000))bn[i]=7;if((b[i]<100000000)&&(b[i]>=10000000))bn[i]=8;
 }
 for(i=1;i<=q;i++) 
 {
  cin>>rn[i]>>u;
  f=true;sc=false;
  for(j=1;j<=n;j++)
  if(sc==false)
  {
   if(rn[i]<=bn[j])
   { 
    k=rn[i];l=8;
    num[8]=b[j]%10;       num[7]=b[j]/10%10;    num[6]=b[j]/100%10;    num[5]=b[j]/1000%10;
	num[4]=b[j]/10000%10; num[3]=b[j]/100000%10;num[2]=b[j]/1000000%10;num[1]=b[j]/10000000%10;
    while(k>0){g=u[k-1]-'0';if(g!=num[l]) f=false;k--;l--;}
    if(f) {cout<<b[j]<<endl; sc=true;continue;}
   }
  } 
   if(f==false)  cout<<-1<<endl;
  
 }
 
 
  return 0;
	
}


