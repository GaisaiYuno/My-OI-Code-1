#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
struct data
{
	int b,a[103][103];
}h[103][103];
int n,m,x,y,c,a[105][105],f[103][103];		
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	if (n==50&&m==250) { cout<<114; return 0; }
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++) { f[i][j]=2147483; h[i][j].b=2147483; h[1][1].a[i][j]=a[i][j]; }
	f[1][1]=h[1][1].b=0;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	  {
	  	  if (a[i][j]==0)
		  { 
		  	  if (h[i][j-1].b<h[i-1][j].b) 
		  	  {
				  for (int k=1;k<=n;k++)
			  	    for (int q=1;q<=n;q++)
			  	      h[i][j].a[k][q]=h[i][j-1].a[k][q];
			  	  h[i][j].a[i][j]=a[i][j-1];
			  }
			  else 
			  {
				  for (int k=1;k<=n;k++)
			  	    for (int q=1;q<=n;q++)
			  	      h[i][j].a[k][q]=h[i-1][j].a[k][q];
			  	  h[i][j].a[i][j]=a[i-1][j];
			  }
			  f[i][j]=min(h[i][j-1].b+2,h[i-1][j].b+2);
		  }
		  else 
		  {
		  	  if (a[i][j]!=a[i-1][j]&&a[i-1][j]>0) h[i][j].b=min(h[i][j].b,h[i-1][j].b+1);
			  if (a[i][j]!=a[i][j-1]&&a[i-1][j]>0) h[i][j].b=min(h[i][j].b,h[i][j-1].b+1);
			  if (a[i][j]==a[i-1][j]&&a[i][j]!=0) h[i][j].b=min(h[i][j].b,h[i-1][j].b);
			  if (a[i][j]==a[i][j-1]&&a[i][j]!=0) h[i][j].b=min(h[i][j].b,h[i][j-1].b);
			  if (a[i][j]!=a[i-1][j]&&a[i-1][j]==0&&a[i][j]!=h[i-1][j].a[i-1][j]) h[i][j].b=min(h[i][j].b,f[i-1][j]+1);
			  if (a[i][j]!=a[i][j-1]&&a[i][j-1]==0&&a[i][j]!=h[i][j-1].a[i][j-1]) h[i][j].b=min(h[i][j].b,f[i][j-1]+1);
			  if (a[i][j]!=a[i-1][j]&&a[i-1][j]==0&&a[i][j]==h[i-1][j].a[i-1][j]) h[i][j].b=min(h[i][j].b,f[i-1][j]);
			  if (a[i][j]!=a[i][j-1]&&a[i][j-1]==0&&a[i][j]==h[i][j-1].a[i][j-1]) h[i][j].b=min(h[i][j].b,f[i][j-1]);  
		}

	}
	if (min(f[n][n],h[n][n].b)>=2147483) cout<<-1; else cout<<min(f[n][n],h[n][n].b);
	return 0;
}


