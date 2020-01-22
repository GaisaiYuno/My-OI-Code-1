#include<iostream>
#include<fstream>
using namespace std;
const int oo=100000000;
int m,n,b[105][105],f[105][105],x,y,c,k,temp;
int s(int x,int y,int zx,int zy)
{	
    if (b[x][y]>=10&&b[zx][zy]==-1||f[x][y]==oo) return oo;
	int sum=0,k=-1;   
	if (b[x][y]>=10) k=b[x][y]-10;else k=b[x][y];
	if (b[zx][zy]==-1) sum=2;else
	if (k!=b[zx][zy]) sum=1;
	return sum+f[x][y];
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=0;i<=m;i++)
	  for (int j=0;j<=m;j++)
	  {
	    b[i][j]=-1;f[i][j]=oo;
	  }
	for (int i=0;i<n;i++)
	{
	  cin>>x>>y>>c;
	  b[x][y]=c;
    }
    f[1][1]=0;
    for (int i=1;i<=m;i++)
    {
    	for (int j=1;j<=m;j++)
    	{
    		k=0;temp=0;
    		if (i!=1||j!=1)
    		{
    		  f[i][j]=s(i-1,j,i,j);
    		  if (b[i][j]==-1) k=b[i-1][j];
    		  temp=s(i,j-1,i,j);
    		  if (temp<f[i][j]) 
			  {
			    f[i][j]=temp;
			    if (b[i][j]==-1) k=b[i][j-1];
			  }
			  if (b[i][j]==-1) b[i][j]=k+10;
    	    }
    	}
    }
    if (f[m][m]==oo) cout<<-1;else cout<<f[m][m];
	return 0;
}
