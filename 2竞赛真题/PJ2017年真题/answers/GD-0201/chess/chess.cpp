#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1000+5][1000+5],xx,yy,cc,minn,f[1000+5][1000+5];
void chess(int x,int y,int s,int c,int p)
{
	if (x==n && y==n)
	{
		if (s<minn) minn=s;
		return;
	}
	if (x+1<=n && f[x+1][y]==0)
	{
		if (a[x+1][y]!=0)
		{
	     	if (a[x+1][y]==c)
		   {
			 f[x+1][y]=1;
			  p=0;
			 chess(x+1,y,s,c,p);
			 f[x+1][y]=0;
		   }
		  else
		  {
			f[x+1][y]=1;
			 p=0;
			chess(x+1,y,s+1,a[x+1][y],p);
			f[x+1][y]=0;
		  }
	   }
	   else
	   {
	   	if (p==0)
	   	{
	    	f[x+1][y]=1;
	    	p=1;
			chess(x+1,y,s+2,c,p);
	   	    f[x+1][y]=0;
	    }
	   }
   }
   if (y+1<=n && f[x][y+1]==0)
	{
		if (a[x][y+1]!=0)
		{
	     	if (a[x][y+1]==c)
		   {
			 f[x][y+1]=1;
			  p=0;
			 chess(x,y+1,s,c,p);
			 f[x][y+1]=0;
		   }
		  else
		  {
			f[x][y+1]=1;
			 p=0;
			chess(x,y+1,s+1,a[x][y+1],p);
			f[x][y+1]=0;
		  }
	   }
	   else
	   {
	   	 if (p==0)
	   	  {
	     	f[x][y+1]=1;
	   	    p=1;
		   chess(x,y+1,s+2,c,p);
	   	   f[x][y+1]=0;
	    }
	   }
   }
   return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	minn=100000000;
	for (int i=1;i<=m;i++)
	{
		cin>>xx>>yy>>cc;
		if (cc==0)
		{
			a[xx][yy]=1;
		}
		if (cc==1)
		{
			a[xx][yy]=2;
		}
	}
	chess(1,1,0,a[1][1],0);
	if (minn==100000000)
	{
		cout<<-1;
	}
	else
	{
		cout<<minn;
	}
	return 0;
}
