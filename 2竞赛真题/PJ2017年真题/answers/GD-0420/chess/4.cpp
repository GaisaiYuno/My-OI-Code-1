#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
long long f[150][150],ff[150][150];int m,n,a[150][150],x,y,c;
int main()
{
     freopen("chess.in","r",stdin);
     freopen("chess.out","w",stdout);
     cin>>m>>n;
     for(int i=1;i<=m;i++)
      for(int j=1;j<=m;j++)
       a[i][j]=3;
     for(int i=1;i<=n;i++)
     {
         cin>>x>>y>>c;
         if(c==1) a[x][y]=2;
         if(c==0) a[x][y]=1;
	 }
	 for(int i=1;i<=m;i++)
	 {
	    for(int j=1;j<=m;j++)
	    {
	    	x=0;y=0;
			if(a[i][j]==1)
			{
			    if(a[i-1][j]==a[i][j])
			      f[i][j]=f[i-1][j];
			    if(a[i-1][j]!=a[i][j])
			    {
				   if(a[i-1][j]==2) f[i][j]=f[i-1][j]+1;
				   if(a[i-1][j]==3) f[i][j]=min(f[i][j],ff[i-1][j]+2);
				}
			}   
	    }
	 }
	 if(f[m][m]!=-1&&ff[m][m]!=-1)cout<<min(f[m][m],ff[m][m]);
	 if(f[m][m]==-1&&ff[m][m]!=-1) cout<<ff[m][m];
	 if(f[m][m]!=-1&&ff[m][m]==-1) cout<<f[m][m];
	 return 0;
}
