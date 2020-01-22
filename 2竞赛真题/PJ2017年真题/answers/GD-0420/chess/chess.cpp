#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
long long y,f[150][150],ff[150][150];int p,m,n,x,c,a[150][150],q[150][150];
int main()
{
     freopen("chess.in","r",stdin);
     freopen("chess.out","w",stdout);
     cin>>m>>n;
     for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    {a[i][j]=3;q[i][j]=1;}
     for(int i=1;i<=n;i++)
     {
         cin>>x>>y>>c;
         if(c==1) a[x][y]=2;
         if(c==0) a[x][y]=1;
	     q[x][y]=0;
	 }
	 p=0;
	 for(int i=2;i<=m;i++)
	 {   
	      if(a[1][i-1]==a[1][i]&&a[1][i]!=3) f[1][i]=f[1][i-1];
	      else
		  { 
		      if(a[1][i]==3) 
			  {  
			   if(p==1)  
				{
				  for(int j=i;j<=m;j++) f[1][j]=-1;
			       break;
				}
			    if(p==0) {f[1][i]=f[1][i-1]+2;p=1;}
			   
			  }
			 if(a[1][i]!=3) f[1][i]=f[1][i-1]+1;
	      }
	 }
	 p=0;
	 for(int i=2;i<=m;i++)
	 {   
	    if(a[i-1][1]==a[i][1]&&a[i][1]!=3) f[i][1]=f[i-1][1];
	    else
		  { 
		      if(a[i][1]==3) 
			  {  
			   if(p==1) 
				{
				  for(int j=i;j<=m;j++) f[j][1]=-1;
			       break;
				}
			    if(p==0) {f[i][1]=f[i-1][1]+2;p=1;}
			  }
			  if(a[i][1]!=3) f[i][1]=f[i-1][1]+1;
	      }
	 }
	 for(int i=2;i<=m;i++)
	 {
	    for(int j=2;j<=m;j++)
	    {
	    	x=0;
		  if(a[i][j]!=3)
		  {
		      if(f[i-1][j]!=-1)
		      {
		        if(a[i-1][j]==a[i][j]||q[i-1][j]==1) {f[i][j]=f[i-1][j];x=1;}
		        if(a[i-1][j]!=a[i][j]&&q[i-1][j]!=1) {f[i][j]=f[i-1][j]+1;x=1;} 
			  } 
	          if(f[i][j-1]!=-1)
	          {
			      if(a[i][j-1]==a[i][j]||q[i][j-1]==1) 
				 {   
				     if(x==1) f[i][j]=min(f[i][j],f[i][j-1]);
				     if(x==0) {f[i][j]=f[i][j-1];x=1;}
				}
				  if(a[i][j-1]!=a[i][j]&&q[i][j-1]!=1)
				 {   
				    if(x==1) f[i][j]=min(f[i][j],f[i][j-1]+1);
				    if(x==0) {f[i][j]=f[i][j-1]+1;x=1;}
				 }
			  }
		      if(x==0) f[i][j]=-1;
		 }   
		  if(a[i][j]==3)
		  {
		      if(f[i-1][j]!=-1)
		      {
			    if(a[i-1][j]!=3)
			     { f[i][j]=f[i-1][j]+2;x=1;}
		      }
			  if(f[i][j-1]!=-1)
		         if(a[i][j-1]!=3) 
		           {f[i][j]=f[i][j-1]+2;x=1;}
		      if(x==0) f[i][j]=-1;
		  }
		}
	 }
     if(f[m][m]!=-1)cout<<f[m][m]+1;
     else cout<<-1;
	 return 0;
}
