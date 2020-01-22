#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int m,n,a[108][108],o[1005],u[1005],p=1,q=1;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=0;
	for(int i=1;i<=n;i++)
	  cin>>o[i]>>u[i];
	for(int i=1;i<=n;i++)
	  cin>>a[o[i]][u[i]];
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	int o=0;
		if(a[i][j+1]==0) o++;
		if(a[i][j-1]==0) o++;
		if(a[i+1][j]==0) o++;
		if(a[i-1][j]==0) o++;
		if(o>=3) a[i][j]=-1;
	  }
	  if(a[m][m]==-1)
	    cout<<-1;
	return 0;
}

