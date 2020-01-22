#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int i,j,h[5]={0,0,0,-1,1},l[5]={0,1,-1,0,0},
m,n,k,co,maxl=100000001,a[101][101],a1,b1;
bool b[101][101],c[101][101];
void find(int x,int y,int z)
{
	int x1,y2;
 	if ( (x==m)&&(y==m) )
	{
		if (z<maxl) maxl=z;
		return;
	}
 	if ( (x<0)||(y<0)||(x>m)||(y>m) ) return;
	x1=x;y2=y;
	if (b[x1][y2]==true)
	for (int i=1;i<=4;i++)
	{
		x=x1+h[i];y=y2+l[i];
 		if ((c[x][y]==false)&&( (x>0)&&(y>0)&&(x<=m)&&(y<=m) ))
		{
			if (a[x][y]==a[x1][y2])	{find(x,y,z);c[x][y]=true;}
			if ( (a[x][y]!=a[x1][y2])&&(a[x][y]!=-1)) {find(x,y,z+1);c[x][y]=true;}
			c[x][y]=false;
		}
	}
	else
	for (int i=1;i<=4;i++)
	{
		x=x1+h[i];y=y2+l[i];
		if ((c[x][y]==false)&&( (x>0)&&(y>0)&&(x<=m)&&(y<=m) ))
		{
			c[x][y]=true;
			if (a[x][y]==a[x1][y2])	find(x,y,z);
			if ( (a[x][y]!=a[x1][y2])&&(a[x][y]!=-1)) find(x,y,z+1);
			if (a[x][y]==-1)
			{
				b[x][y]=true;
				for (k=0;k<=1;k++) 
				{
			  	a[x][y]=k;
			  	find(x,y,z+2);	
				}
				b[x][y]=false;a[x][y]=-1;
			}
			c[x][y]=false;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	memset(a,-1,sizeof(a));
	c[1][1]=true;
	for (i=1;i<=n;i++) 
	{
		cin>>a1>>b1>>co;
		a[a1][b1]=co;
	}
	find(1,1,0);
	if ( ( (a[m-1][m-1]==-1)&&(a[m-1][m]==-1)&&(a[m][m-1==-1]) )||(maxl==100000001) ) {cout<<"-1";return 0;}
	else cout<<maxl;
	return 0;
}
//sort(,)
//memset(,0,sizeof())
