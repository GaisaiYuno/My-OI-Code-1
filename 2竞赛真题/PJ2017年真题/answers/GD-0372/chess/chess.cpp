#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
   freopen("chess.in","r",stdin);
   freopen("chess.out","w",stdout);
   int m,n,a[105][105],b[105][105],sum[5],x,y,p,x1,y1,ans=0,min=10000;
   bool f;	
   cin>>m>>n;
   for (int i=1;i<=m+1;i++)
    for (int j=1;j<=m+1;j++)
     {
       a[i][j]=0;
       b[i][j]=0;
     }
   for (int i=2;i<=m+1;i++)
    for (int j=2;j<=m+1;j++)  
      a[i][j]=2;
   for (int i=1;i<=n;i++)
    {
      cin>>x>>y>>p;
	  a[x+1][y+1]=p;
	  ans=x-x1+y-y1;
	  if (ans>=3) f=false;
	  x1=x;
	  y1=y;
    }
   if (f==true) 
    for (int i=2;i<=m+1;i++)
     for (int j=2;j<=m+1;j++)
     {
       if (a[i][j-1]+a[i][j]==0) sum[1]=0+b[i][j-1];
       if (a[i][j-1]+a[i][j]==1) sum[1]=1+b[i][j-1];
       if (a[i][j-1]+a[i][j]==3) sum[1]=2+b[i][j-1];
       if (a[i][j-1]+a[i][j]==4) sum[1]=4+b[i][j-1];
       if ((a[i][j-1]==1)&&(a[i][j]==1)) sum[1]=0+b[i][j-1]; 
	   if ((a[i][j-1]+a[i][j]==2)&&(a[i][j-1]!=1)) sum[1]=2+b[i][j-1];
	   
	   if (a[i][j+1]+a[i][j]==0) sum[2]=0+b[i][j+1];
       if (a[i][j+1]+a[i][j]==1) sum[2]=1+b[i][j+1];
       if (a[i][j+1]+a[i][j]==3) sum[2]=2+b[i][j+1];
       if (a[i][j+1]+a[i][j]==4) sum[2]=4+b[i][j+1];
       if ((a[i][j+1]==1)&&(a[i][j]==1)) sum[2]=0+b[i][j+1]; 
	   if ((a[i][j+1]+a[i][j]==2)&&(a[i][j+1]!=1)) sum[2]=2+b[i][j+1];
	   
	   if (a[i+1][j]+a[i][j]==0) sum[3]=0+b[i+1][j];
       if (a[i+1][j]+a[i][j]==1) sum[3]=1+b[i+1][j];
       if (a[i+1][j]+a[i][j]==3) sum[3]=2+b[i+1][j];
       if (a[i+1][j]+a[i][j]==4) sum[3]=4+b[i+1][j];
       if ((a[i+1][j]==1)&&(a[i][j]==1)) sum[3]=0+b[i+1][j]; 
	   if ((a[i+1][j]+a[i][j]==2)&&(a[i+1][j]!=1)) sum[3]=2+b[i+1][j];
	   
	   if (a[i-1][j]+a[i][j]==0) sum[4]=0+b[i-1][j];
       if (a[i-1][j]+a[i][j]==1) sum[4]=1+b[i-1][j];
       if (a[i-1][j]+a[i][j]==3) sum[4]=2+b[i-1][j];
       if (a[i-1][j]+a[i][j]==4) sum[4]=4+b[i-1][j];
       if ((a[i-1][j]==1)&&(a[i][j]==1)) sum[4]=0+b[i-1][j]; 
	   if ((a[i-1][j]+a[i][j]==2)&&(a[i][j]!=1)) sum[4]=2+b[i-1][j];
	   
	   min=10000;
	   for (int k=1;k<=4;j++)
	    if (sum[k]<min) min=sum[k];
	   b[i][j]=min;	   	
     }
	if (f==false) cout<<"-1";  
    if (f==true)  cout<<b[m+1][m+1];
    return 0;
}
