#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,x,y,z,t,w,a[105][105],b[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	if (m<n) {cout<<-1;return 0;}
	b[n][n]=n*n+1;
	for (int i=1;i<=m;i++)
	  {
	     scanf("%d%d%d",&x,&y,&z);
	     a[x][y]=z+1;
      }
    if (n-x>1||n-y>1) {cout<<-1;return 0;}
    b[1][1]=0;
    for (int i=2;i<=n;i++)
      {
      	if (a[1][i]==a[1][i-1]&&a[1][i]!=0)
		  b[1][i]=b[1][i-1];
      	if (a[1][i]!=a[1][i-1]&&a[1][i]!=0&&a[1][i-1]!=0)
      	  b[1][i]=b[1][i-1]+1;
      	if (a[1][i]==0&&a[1][i-1]==0)
      	{
		  for (int j=i;j<=n;j++) a[1][j]=3;
		  break;
	    }
      	if (a[1][i]==0&&a[1][i-1]!=0)
      	{
      	  if (a[2][i]==0) a[1][i]=3;
      	  else {a[1][i]=a[2][i];b[1][i]=b[1][i-1]+2;}
      	}
      }
    for (int i=2;i<=n;i++)
      {
      	if (a[i][1]==a[i-1][1]&&a[i][1]!=0)
      	  b[i][1]=b[i-1][1];
      	if (a[i][1]!=a[i-1][1]&&a[i][1]!=0&&a[i-1][1]!=0)
      	  b[i][1]=b[i-1][1]+1;
      	if (a[i][1]==0&&a[i-1][1]==0)
      	{
      	  for (int j=i;j<=n;j++) a[j][1]=3;
		    break;
		}
      	if (a[i][1]==0&&a[i-1][1]!=0)
      	{
      	  if (a[i][2]==0) a[i][1]=3;
      	  else {a[i][1]=a[i][2];b[i][1]=b[i-1][1]+2;}
      	}
      }
    for (int i=2;i<=n;i++)
     for (int j=2;j<=n;j++)
      {
      	t=0;w=0;
		if (a[i][j]==a[i-1][j]&&a[i][j]!=0&&a[i][j]!=3)
      	  {t=1;b[i][j]=b[i-1][j];}
      	if (a[i][j]==a[i][j-1]&&a[i][j]!=0&&a[i][j]!=3)
      	  {
			if (t==0) b[i][j]=b[i][j-1];
			else b[i][j]=min(b[i][j],b[i][j-1]);
		  }
		if (t==1) continue;
      	
      	if (a[i][j]!=a[i-1][j]&&a[i][j]!=0&&a[i-1][j]!=0&&a[i][j]!=3&&a[i-1][j]!=3)
      	  {t=1;b[i][j]=b[i-1][j]+1;}
      	if (a[i][j]!=a[i][j-1]&&a[i][j]!=0&&a[i][j-1]!=0&&a[i][j]!=3&&a[i][j-1]!=3)
      	  if (t==0) b[i][j]=b[i][j-1]+1;
      	  else b[i][j]=min(b[i][j]+1,b[i][j-1])+1;
      	
      	if (a[i][j]==0&&a[i][j-1]!=0)
      	{
      	  if (a[i][j+1]==0) a[i][j]=a[i+1][j];
      	  else a[i][j]=a[i][j+1];
      	  t=1; b[i][j]=b[i][j-1]+2;
      	}
      	if (a[i][j]==0&&a[i-1][j]!=0)
      	{
      	  if (t==0) b[i][j]=b[i-1][j]+2;
      	  else b[i][j]=min(b[i][j]+2,b[i-1][j]);
      	}
      }
    if (b[n][n]==n*n+1) cout<<-1;
    else cout<<b[n][n];
	return 0;
}
