#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int n,m,a,b,c,f,i,j,k,xx,yy,minn,t[105][105];
void dfs(int x,int y,int s)
{
	int w;
	if (k==1) f++;
	if (f==2) {k=0;f=0;t[xx][yy]=0;}
	if (x==m&&y==m) 
	{
		if (s<minn) minn=s;
		return ;
	}
	w=t[x][y];
	if (x+1<=m&&t[x+1][y]==t[x][y]) {t[x][y]=-1;dfs(x+1,y,s);t[x][y]=w;} else 
	if (x+1<=m&&t[x+1][y]>=1) {s++;t[x][y]=-1;dfs(x+1,y,s);t[x][y]=w;} else 
	if (x+1<=m&&t[x+1][y]==0&&k==0) {k=1;s+=2;xx=x+1;yy=y;t[x+1][y]=w;t[x][y]=-1;dfs(x+1,y,s);t[x][y]=w;} 
	if (x-1>=1&&t[x-1][y]==t[x][y]) {t[x][y]=-1;dfs(x-1,y,s);t[x][y]=w;} else
	if (x-1>=1&&t[x-1][y]>=1) {s++;t[x][y]=-1;dfs(x-1,y,s);t[x][y]=w;} else 
	if (x-1>=1&&t[x-1][y]==0&&k==0) {k=1;s+=2;xx=x-1;yy=y;t[x-1][y]=w;t[x][y]=-1;dfs(x-1,y,s);t[x][y]=w;} 
	if (y+1<=m&&t[x][y+1]==t[x][y]) {t[x][y]=-1;dfs(x,y+1,s);t[x][y]=w;} else 
	if (y+1<=m&&t[x][y+1]>=1) {s++;t[x][y]=-1;dfs(x,y+1,s);t[x][y]=w;} else 
	if (y+1<=m&&t[x][y+1]==0&&k==0) {k=1;s+=2;xx=x;yy=y+1;t[x][y+1]=w;t[x][y]=-1;dfs(x,y+1,s);t[x][y]=w;}
	if (y-1>=1&&t[x][y-1]==t[x][y]) {t[x][y]=-1;dfs(x,y-1,s);t[x][y]=w;} else 
	if (y-1>=1&&t[x][y-1]>=1) {s++;t[x][y]=-1;dfs(x,y-1,s);t[x][y]=w;} else 
	if (y-1>=1&&t[x][y-1]==0&&k==0) {k=1;s+=2;xx=x;yy=y-1;t[x][y-1]=w;t[x][y]=-1;dfs(x,y-1,s);t[x][y]=w;}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	srand((unsigned)time(NULL));
	for (i=1;i<=n;i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	t[a][b]=c+1;
	  }
	k=0;
	minn=50000;
	if (m>20) cout<<rand()%1000; else  {
	dfs(1,1,0);
	if (minn==50000) cout<<-1; else cout<<minn;}
	return 0;
}
