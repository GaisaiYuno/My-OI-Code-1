#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,m,ans,x,y,p,a[200][200],f[200][200][4];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<=n;i++)
	 for (int j=0;j<=n;j++) 
	  { a[i][j]=-1; 
	    f[i][j][0]=10000000;
	    f[i][j][1]=10000000;
	 }
	for (int i=1;i<=m;i++)
	 { cin>>x>>y>>p; a[x][y]=p; }
	if (a[1][1]!=-1) f[1][1][a[1][1]]=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  {
	  	if (a[i][j]!=-1||a[i][j-1]!=-1)
	  	 {
	  	 	if (a[i][j]==0||a[i][j]==-1)
	  	 	 {
	  	 	  f[i][j][0]=min(f[i][j][0],f[i][j-1][0]);
	  	 	  f[i][j][0]=min(f[i][j][0],f[i][j-1][1]+1);
	  	     }
	  	    if (a[i][j]==1||a[i][j]==-1) 
			  {
	  	 	  f[i][j][1]=min(f[i][j][1],f[i][j-1][1]);
	  	 	  f[i][j][1]=min(f[i][j][1],f[i][j-1][0]+1);
	  	     }
	  	    if (a[i][j]==-1) { f[i][j][0]+=2; f[i][j][1]+=2; }
	  	 }
	  	 
	  	if (a[i][j]!=-1||a[i-1][j]!=-1)
		  {
	  	 	if (a[i][j]==0||a[i][j]==-1)
	  	 	 {
	  	 	  f[i][j][0]=min(f[i][j][0],f[i-1][j][0]);
	  	 	  f[i][j][0]=min(f[i][j][0],f[i-1][j][1]+1);
	  	     }
	  	    if (a[i][j]==1||a[i][j]==-1) 
			  {
	  	 	  f[i][j][1]=min(f[i][j][1],f[i-1][j][1]);
	  	 	  f[i][j][1]=min(f[i][j][1],f[i-1][j][0]+1);
	  	     }
		   if (a[i][j]==-1) { f[i][j][0]+=2; f[i][j][1]+=2; }
	  	 }
      }
    ans=min(f[n][n][0],f[n][n][1]);
    if (ans>=10000000) cout<<-1; else cout<<ans;
	return 0;
}
