#include<iostream>
#include<cstdio>
using namespace std;
int a[106][1006],ans=0,cd=1;

int main()
{
	//freopen("chess.in","r",stdin);
	//freopen("chess.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	    a[i][j]=2;
	for (int i=1;i<=n;i++)
	  {
	  	int x,y,c;
	  	cin>>x>>y>>c;
	  	a[x][y]=c;
	  }  
	if (a[m][m]==2&&a[m-1][m]==2&&a[m][m-1]==2) {cout<<-1;return 0;}
	int b[1006][1006],i=1,j=1;
	b[1][1]=0;
	while (i==m&&j==m)
	{
	  int xs=1,xx=1;
	  if (a[i][j]==0) {
	  	               cd=1; 
			           if (a[i][j+1]==2) if (cd) {a[i][j+1]=a[i][j];cd=0;}
					                     else xs=0; 
					   b[i][j+1]=b[i][j]+a[i][j]+a[i][j+1];
	                   b[i+1][j]=b[i][j]+a[i][j]+a[i+1][j];
					  }
	  if (a[i][j]==1) {
	  	               cd=1;
	                   if (a[i+1][j]==2) if (cd) {a[i][j+1]=a[i][j];cd=0;}
					                     else xx=0;
					   b[i][j+1]=b[i][j]+a[i][j]-a[i+1][j];
	                   b[i+1][j]=b[i][j]+a[i][j]-a[i+1][j];
					   }
	  if (xs==0&&xx==0) {cout<<-1;return 0; }
	  else if (xs) j++;
	       else if (xx==0) i++;
		        else if (b[i][j+1]<=b[i+1][j]) j++;
		             else i++;
	}
	cout<<b[m][m];
	return 0;
}
