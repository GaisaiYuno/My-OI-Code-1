#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
struct data
{
	int x,y,q,sf;
};
data bc[50005];
int  map[105][105],f[105][105];
int n,m,h,t,mi,z,d,a[105][105],k,b,c;
void pd(int x,int y,int q,int s,int p)
{
	if (x>=1&&x<=k&&y>=1&&y<=k&&a[x][y]==0)
	{
		if (map[x][y]==0&&s==0) 
		{
			if (x==k&&y==k) {mi=min(mi,q+2); d=1;}
			t++;
			bc[t].x=x;
			bc[t].y=y;
			bc[t].q=q+2;
			bc[t].sf=1;
		    f[x][y]=p;
		}
		if (map[x][y]!=0) 
		{
		    if (map[x][y]==p) 
			{
			if (x==k&&y==k) {mi=min(mi,q); d=1;}
			t++;
			bc[t].x=x;
			bc[t].y=y;
			bc[t].q=q;
			bc[t].sf=0;
			} 
			else
			{
			if  (x==k&&y==k) {mi=min(mi,q+1); d=1;}
			t++;
			bc[t].x=x;
			bc[t].y=y;
			bc[t].q=q+1;
			bc[t].sf=0;
			}
	   	}
	}
	return;
}
void bfs(int x,int y)
{
	h=1;
	t=1;
	bc[1].x=x;
	bc[1].y=y;
	bc[1].q=0;
	bc[1].sf=0;
	while (h<=t)
	{
		int xx=bc[h].x;
		int yy=bc[h].y;
		int qq=bc[h].q;
		int sf=bc[h].sf;
		int p=0;
		if (sf==1) p=f[xx][yy];
		else  p=map[xx][yy];
		a[xx][yy]=1;
		pd(xx+1,yy,qq,sf,p);
		pd(xx-1,yy,qq,sf,p);
		pd(xx,yy+1,qq,sf,p);
		pd(xx,yy-1,qq,sf,p);
		h++;
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	mi=999999;
	cin>>n>>m;
	k=n;
	for (int i=1; i<=m; i++)
	{
		cin>>b>>c>>z;
		if (z==0) map[b][c]=1;
		if (z==1) map[b][c]=2;
	}
	bfs(1,1);
	if (d==1) cout<<mi;
	else cout<<-1;
	return 0;
}
