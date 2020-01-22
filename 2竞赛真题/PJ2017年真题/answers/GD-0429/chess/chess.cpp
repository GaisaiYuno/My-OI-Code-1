#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[10000][10000],s;
int x,y,c,i,j,w;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
    {
      cin>>x>>y>>c;
	  if(c==0)
	  c=2;
      a[x][y]=c;
    }
   /*      for(int i=1;i<=m;i++)
	     {
	       for(int j=1;j<=m;j++)
	        cout<<a[i][j]<<' ';
	       cout<<endl;
	     }*/
	     while(i<m)
	     {
               if(j==m)
               i++;
               if(i==m)
               break;
	       	  if(a[i][j+1]==a[i][j])
	       	   j++;
	       	   else
	       	   {
	       	   	if(a[i+1][j]==a[i][j])
	       	    i++;
	       	   }
	       	   if(a[i][j+1]!=a[i][j] && a[i][j+1]!=0)
	       	   {
	       	   	  j++; 
				  s++;
	       	   }
	       	   else
	       	   {
	       	   	  if(a[i+1][j]!=a[i][j] && a[i+1][j]!=0)
	       	      i++; s++;
	       	   }
	       	   if(a[i][j+1]==0 && a[i+1][j]==0)
	       	   {
	       	   	  s+=2;
	       	   	  a[i][j+1]=a[i][j];
	       	   	  j++;
	       	   	  if(a[i][j+1]==0 && a[i+1][j]==0)
	       	   	  {
	       	   	   w++;
	       	   	   cout<<-1;
	       	   	   break;
	       	   	  }
	       	   }
	     }
	    if(w==0)
	   cout<<s;
	return 0;
}
