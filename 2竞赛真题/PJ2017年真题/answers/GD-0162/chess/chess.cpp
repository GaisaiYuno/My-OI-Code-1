#include<iostream>
#include<cstdio>
using namespace std;
int m,n,jh,i,j,x1,y1,c,a[2017][2017],ans;
int qp( int x,int y )
{
	if (x==m&&y==m) cout<<ans;
	if (a[x][y]==a[x+1][y]) { ans+=0; jh=1; qp(x+1,y); return 0;}
	if (a[x][y]==a[x][y+1]) { ans+=0; jh=1; qp(x,y+1); return 0;}
	if (a[x][y]>=2&&a[x+1][y]>=2&&a[x][y]!=a[x+1][y]) { ans+=1; jh=1; qp(x+1,y); return 1;}
	if (a[x][y]>=2&&a[x][y+1]>=2&&a[x][y]!=a[x+1][y]) { ans+=1; jh=1; qp(x,y+1); return 1;}
	if (a[x+1][y]==1&&jh==1) { ans+=2; jh=0; a[x+1][y]=a[x][y]; qp(x+1,y); return 2;}
	if (a[x][y+1]==1&&jh==1) { ans+=2; jh=0; a[x][y+1]=a[x][y]; qp(x,y+1); return 2;}
	if (a[x+1][y]==1&&a[x][y+1]==1) { cout<<-1; return 0;}
}
int main()
{
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	cin>>m>>n;
	jh=1;
	for (i=1;i<=m;i++)
	for (j=1;j<=m;j++)
	    a[i][j]=1;
	for (i=1;i<=n;i++)
	{
		cin>>x1>>y1>>c;
		a[x1][y1]=c+2;
	}
    qp(1,1);
}
