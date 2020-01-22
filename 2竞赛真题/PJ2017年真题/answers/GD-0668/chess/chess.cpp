#include<iostream>
#include<cstdio>
using namespace std;
int m,n,q,w,c,a[105][105],b[105][105],x[5]={0,0,0,1,-1},y[5]={0,1,-1,0,0},e[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	  {
	  	cin>>q>>w>>c;
	  	a[q][w]=c+1;
	  }
	a[0][1]=a[1][1];
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++) b[i][j]=10005;
	b[m+1][m]=10005;
	b[m][m+1]=10005;
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	    {
	    	for (int k=1;k<=4;k++)
	    	  {
	    	  if (a[i+x[k]][j+y[k]]!=0&&a[i][j]!=0) 
	    	    {
	    	    	if (a[i+x[k]][j+y[k]]==a[i][j]) b[i][j]=min(b[i][j],b[i+x[k]][j+y[k]]);
	    	  	     else b[i][j]=min(b[i][j],b[i+x[k]][j+y[k]]+1);
	    	    }
	    	   else
	    	    {
	    	   	    if (a[i+x[k]][j+y[k]]==0&&a[i][j]!=0) 
				      {
				      	if (e[i+x[k]][j+y[k]]!=a[i][j]) b[i][j]=min(b[i][j],b[i+x[k]][j+y[k]]+1);
				      	  else b[i][j]=min(b[i][j],b[i+x[k]][j+y[k]]);
				      }
	    	   	    if (a[i+x[k]][j+y[k]]!=0&&a[i][j]==0) 
					  {
					    if (b[i][j]>b[i+x[k]][j+y[k]]+2)
					      {
					      	b[i][j]=b[i+x[k]][j+y[k]]+2;
					      	e[i][j]=a[i+x[k]][j+y[k]];
					      }
				      }
	    	    }
	          }
	    }
	if (b[m][m]==10005) cout<<-1;
	  else cout<<b[m][m];
	return 0;
}
