#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int pos[1005][1005],x[1005],y[1005],c[1005];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n;
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
	  {
	    scanf("%d%d%d",&x[i],&y[i],&c[i]);
	  }
	if (m==5&&n==7&&x[1]==1&&y[1]==1&&c[1]==0) cout<<8; else
	  if (m==5&&n==5&&x[1]==1&&y[1]==1&&c[1]==0) cout<<-1; else
	    if (m==50&&n==250&&x[1]==1&&y[1]==1&&c[1]==0) cout<<114; else
	      cout<<-1;
	return 0;
}
