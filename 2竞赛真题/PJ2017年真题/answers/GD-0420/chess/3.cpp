#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
int mi=10000000;int p,m,n,x,c,a[150][150],q[150][150],f,y;
void pp(int x,int y,int s,int q)
{
    if(x==m&&y==m)
    {
	  if(mi>s&&s!=-1) {mi=s;f=1;}
	   return ;
	}
	if(s!=-1)
	{
	  if(a[x][y+1]==a[x][y]&&y<m) pp(x,y+1,s,0);
	  if(a[x][y+1]!=a[x][y]&&y<m)
	  {
	   if(a[x][y+1]!=3) pp(x,y+1,s+1,0);
	   else
	   {
	       if(p==0)
	       {
		     a[x][y+1]=1;
	         pp(x,y+1,s+2,1);
	         a[x][y+1]=2;
	         pp(x,y+1,s+2,1);
	       }
	       if(p==1)
	        pp(x,y+1,-1,0);
	   }
	}
	if(a[x+1][y]==a[x][y]&&x<m) pp(x+1,y,s,0);
	if(a[x+1][y]!=a[x][y]&&x<m)
	{
	   if(a[x+1][y]!=3) pp(x+1,y,s+1,0);
	   else
	   {
	       if(p==0)
	       {
		     a[x+1][y]=1;
	         pp(x+1,y,s+2,1);
	         a[x+1][y]=2;
	         pp(x+1,y,s+2,1);
	       }
	       if(p==1)
	        pp(x+1,y,-1,0);
	   }
	}
    }  
    if(s==-1)
       return;
}
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
	 pp(1,1,0,0);
	 if(f==0) cout<<-1;
	 else cout<<mi;
	 return 0;
}
