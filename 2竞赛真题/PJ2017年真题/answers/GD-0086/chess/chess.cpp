#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;
struct data
{
	long long x,y,t,magic;
};
data opens[1000000+10];
long long m,n,x,y,c,head,tail,xx,yy,tt,xxx,yyy;
long long mi=2147483647; 
long long a[100+10][100+10];
int dx[3]={0,1,0},dy[3]={0,0,1};
void color(int xx,int yy,int ttt,bool bb) 
{
	if (a[xx][yy]==a[opens[head].x][opens[head].y]) 
     {
		tail++;
		opens[tail].x=xx;
		opens[tail].y=yy;
	    opens[tail].t=ttt;
		if (bb==true) opens[tail].magic=1;
		if (opens[tail].x==m && opens[tail].y==m) mi=min(opens[tail].t,mi);
	} 
	if (a[xx][yy]!=a[opens[head].x][opens[head].y]) 
	{
		tail++;
		opens[tail].x=xx;
		opens[tail].y=yy;
        opens[tail].t=ttt+1;
		if (bb==true) opens[tail].magic=1;
		if (opens[tail].x==m && opens[tail].y==m) mi=min(opens[tail].t,mi);
    } 
}
void bfs()
{
	head=1;
	tail=1;
	opens[head].x=1;
	opens[head].y=1;
	while (head<=tail)
	  {
	  	for (int i=1;i<=2;i++)
	  	  {	
			xx=opens[head].x+dx[i];
	  	    yy=opens[head].y+dy[i];
	  	    tt=opens[head].t;
			if (xx<1 || xx>m || yy<1 || yy>m) continue;
	  	    if (a[xx][yy]!=0) 
			    color(xx,yy,tt,false);
			if (a[xx][yy]==0 && opens[head].magic==0) 
			     {
			     	tt+=2;
					a[xx][yy]=1; 
					color(xx,yy,tt,true);
				    for (int i=1;i<=2;i++)
	  	            {	
			           xxx=xx+dx[i];
	  	               yyy=yy+dy[i];
	  	               if (a[xxx][yyy]!=0)
	  	               if (xxx>1 && xxx<m && yyy>1 && yyy<m) color(xxx,yyy,tt,false);
	  	              }
					a[xx][yy]=2; 
					color(xx,yy,tt,true);
				    for (int i=1;i<=2;i++)
	  	            {	
			          xxx=xx+dx[i];
	  	              yyy=yy+dy[i];
	  	              if (a[xxx][yyy]!=0)
	  	              if (xxx>1 && xxx<m && yyy>1 && yyy<m) color(xxx,yyy,tt,false);
	  	            }
	  	           a[xx][yy]=0;
				 }
		  }
		head++;
	  }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	  {cin>>x>>y>>c;
	   if (c==1) a[x][y]=1; 
	   if (c==0) a[x][y]=2;
      }
    bfs();
    if (m==1) {cout<<1; exit(0);}
    if (mi==2147483647) cout<<-1;
                   else cout<<mi;
	return 0;
}
