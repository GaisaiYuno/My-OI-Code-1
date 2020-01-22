#include<iostream>
#include<fstream>
using namespace std;
int a,b,c,m,n,x,y,zs1,zs2,w,p,zs,t[2000][2000];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	 for (int j=1;j<=m;j++)
	  t[i][j]=3;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		t[a][b]=c;
	}
    x=1;
    y=1;
    zs1=0;
    w=1;
	while (w==1 && x<=m && y<=m)
	{
		zs2++;
		p=0;
	    if (y+1<=m && t[x][y+1]==t[x][y] &&(t[x][y+1]==0 || t[x][y+1]==1)) 
		 {
		 	p=1;
		 	y++;
		 }
		else if (x+1<=m && t[x+1][y]==t[x][y] && (t[x+1][y]==0 || t[x+1][y]==1)) 
		{
			p=1;
			x++;
		}
		if (p==0) 
		{
		     if (y+1<=m && (t[x][y+1]==1 || t[x][y+1]==0) )
		     {
		 	     p=1;
		 	     y++;
		 	     if (t[x][y+1]==1) t[x][y+1]==0;
			      else if (t[x][y+1]==0) t[x][y+1]==1;
			     zs++;
		     }
		    else if (x+1<=m && (t[x+1][y]==1 || t[x+1][y]==0)) 
		    {
			    p=1;
			    x++;
			    if (t[x+1][y]==1) t[x+1][y]==0;
			     else if (t[x+1][y]==0) t[x+1][y]==1;
			    zs++;
		    }
		}
		if (p==0)
		{
			if (zs2-zs1>1 || zs1==0) 
			 {
			   t[x][y+1]=t[x][y];
			   y++;
			   zs+=2;
			   zs1=zs2;
		     }
		    else if (zs2-zs1<=1) 
		    {
		    	cout<<"-1";
		    	w=0;
		    }
		}
		if (x==m && y==m) break; 
	}
	if (w==1) cout<<zs;
	return 0;
}
