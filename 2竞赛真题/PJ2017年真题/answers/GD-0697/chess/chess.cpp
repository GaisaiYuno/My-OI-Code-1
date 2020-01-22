#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;

int h[101],l[101],k[101][101],co[1001],m,n,c=1000000,a[10]={0,-1,1,0,0},b[10]={0,0,0,-1,1};
bool mf=true,d=false,kk[101][101],kkk[101][101];
void f(int x,int y,int z)
{
  int hh,ll;
  if((x==m)&&(y==m)){ d=true;if(z<c) c=z; return;}
  if((x>m)||(y>m)) return;

  for(int i=1;i<=4;i++)
  {
  	  
	  hh=x+a[i];ll=y+b[i];
  	  if((hh<=m)&&(ll<=m)&&(hh>=1)&&(ll>=1)&&(kk[hh][ll]==false))
  	  {
  	   if(k[hh][ll]!=-1)
	   {
	    kk[hh][ll]=true;
	   	if(k[hh][ll]==k[x][y]) f(hh,ll,z);
	    else f(hh,ll,z+1);
	    kk[hh][ll]=false;
	   }	
  		
  	   else	
  	   {
  	   	if(kkk[x][y]==true) mf=false;else mf=true;
  	   	if(mf)
  	   	{
  	   	 kk[hh][ll]=true;k[hh][ll]=k[x][y];kkk[hh][ll]=true;
  	   	 f(hh,ll,z+2);
  	   	 k[hh][ll]=-1; kk[hh][ll]=false;
  	   	} 
  	   
	   }
    } 
  		
  }

};


int main( )
{
 freopen ( "chess.in","r",stdin);
 freopen ( "chess.out","w",stdout);

 int i,d,s=0;

 cin>>m>>n;

 for(int i=1;i<=100;i++)
 for(int j=1;j<=100;j++) k[i][j]=-1;
 for(i=1;i<=n;i++) {cin>>h[i]>>l[i]>>co[i];k[h[i]][l[i]]=co[i];}
 kk[1][1]=true;
 f(1,1,0);
 if((d==false)||(c==1000000)) cout<<-1;
 else cout<<c;
 return 0;
	
}









