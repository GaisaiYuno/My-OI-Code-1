#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int m,n,a,b,cc,f[1005][1005],x,y,c[1005][1005],d[1005][1005];
void ff(int x,int y,int xx,int yy)
{
	if (x>0&&y>0&&x<=m&&y<=m)
	{
	if (f[x][y]==f[xx][yy]&&f[xx][yy]!=0)if (c[x][y]<c[xx][yy])c[xx][yy]=c[x][y];
    if (f[x][y]!=f[xx][yy]&&f[xx][yy]!=0)if (c[x][y]+1<c[xx][yy])c[xx][yy]=c[x][y]+1;
	if (f[x][y]==0&&f[xx][yy]!=0)
	if (c[x][y]<c[xx][yy])c[xx][yy]=c[x][y];
	if (f[x][y]!=0&&f[xx][yy]==0)
	if (c[x][y]+2<c[xx][yy])c[xx][yy]=c[x][y]+2;
}
}
int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
   cin>>m>>n;
   for (int i=1;i<=n;i++)
    {cin>>a>>b>>cc;
     if (cc==0)f[a][b]=2;
     else f[a][b]=1;
    }
  for (int i=1;i<=m;i++)
  for (int j=1;j<=m;j++)
   c[i][j]=1000000000;
   c[1][1]=0;
 for (int i=2;i<=m;i++)
 	ff(1,i-1,1,i);
 for (int i=2;i<=m;i++)
    ff(i-1,1,i,1); 

 for (int i=2;i<=m;i++)
  for (int j=2;j<=m;j++)
   {
   	 ff(i,j-1,i,j);
   	 ff(i,j+1,i,j);
   	 ff(i-1,j,i,j);
   	 ff(i+1,j,i,j);
   }

if (c[m][m]!=1000000000)cout<<c[m][m]+1;
else cout<<-1;
   return 0;
}
