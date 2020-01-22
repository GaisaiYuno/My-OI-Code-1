#include<iostream>
#include<cstdio>
using namespace std;
long long mxx,b[100009],c[10000],a[1000][1000],d[1000][1000],q,w,u,e,n,m,z;
void f(int x,int y,int g,int k)
{
    if (x==n&&y==n)
	  {
	  	if (g<mxx) mxx=g;
	  	return;
	  }	
	 int i; 
	for (i=1;i<=4;i++)
	  {
	  	 if (x+b[i]<=n&&x+b[i]>0&&y+c[i]<=n&&y+c[i]>0&&d[x+b[i]][y+c[i]]==0)
	  	   {
	  	   	 if (a[x][y]!=a[x+b[i]][y+c[i]])
	  	   	   {
	  	   	   	 if (a[x+b[i]][y+c[i]]==0)
	  	   	   	   {
	  	   	   	   	if (k==0)
	  	   	   	   	  {
	  	   	   	   	  	 g=g+2;
	  	   	   	   	  	 k=1;
	  	   	   	   	  	 z=a[x][y];
	  	   	   	   	  	 d[x][y]=1;
	  	   	   	   	  	 x=x+b[i];
	  	   	   	   	  	 y=y+c[i];
	  	   	   	   	  	 f(x,y,g,k);
	  	   	   	   	  	 d[x][y]=0;
	  	   	   	   	  	 g=g-2;
	  	   	   	   	  	 x=x-b[i];
	  	   	   	   	  	 y=y-c[i];
	  	   	   	   	  	
	  	   	   	   	  	 k=0;
	  	   	   	   	  }
	  	   	   	    if (k==1)
	  	   	   	      {
	  	   	   	      	return;
	  	   	   	      }
	  	   	   	   }
	  	   	   	   
	  	   	   	 else 
				   {
				   	if (k==1)
				   	  {
				   	  	if (a[x+b[i]][y+c[i]]==z) g=g-1;
				   	  }
				   	k=0;
				    g=g+1;
				   	d[x][y]=1;
	  	   	   	   	x=x+b[i];
	  	   	   	   	y=y+c[i]; 
	  	   	   	   	f(x,y,g,k);
	  	   	   	   	d[x][y]=0;
	  	   	   	   	x=x-b[i];
	  	   	   	   	y=y-c[i]; 
	  	   	   	   	g=g-1;
	  	   	   	   	if (a[x][y]==0) k=1;
				   } 
				    
	  	   	   }
	  	   	   
	  	   	 else 
	  	   	 if (a[x+b[i]][y+c[i]]!=0||k!=1)
	  	   	   {
	  	   	   	    k=0;
	  	   	   	 	d[x][y]=1;
	  	   	   	   	x=x+b[i];
	  	   	   	   	y=y+c[i]; 
	  	   	   	 
	  	   	   	   	f(x,y,g,k);
	  	   	   	   	d[x][y]=0;
	  	   	   	   	x=x-b[i];
	  	   	   	   	y=y-c[i]; 
	  	   	   	   	if (a[x][y]==0) k=1;
	  	   	   }
	  	   }
	  }
	  if (i!=0) return ;
}

int main()
{
	 freopen("chess.in","r",stdin);
     freopen("chess.out","w",stdout);
	cin>>n>>m;
	mxx=1999999;
	b[1]=0;b[2]=1;b[3]=0;b[4]=-1;
	c[1]=1;c[2]=0;c[3]=-1;c[4]=0;
	for (u=1;u<=m;u++)
	  {
	  	cin>>q>>w>>e;
	  	a[q][w]=e+1;
	  }

	  f(1,1,0,0);
	if (mxx!=1999999)cout<<mxx;else cout<<-1;
	return 0;
}
