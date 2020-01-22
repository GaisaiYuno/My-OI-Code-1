#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,y,colour,i,j,f1,f2,f3,f4,min1,min2,f[101][101]={0},ff[101][101]={0},a[101][101]={0};
bool zh[101][101]={0};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	  {
	  	scanf("%d%d%d",&x,&y,&colour);
	  	f[x][y]=colour+1;
	  	ff[x][y]=colour+1;
	  }
	for (i=0;i<=n+1;i++)
	  for (j=0;j<=n+1;j++) a[i][j]=10000000;
	a[1][1]=0;
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	  if (f[i][j]>0)
	  {
	  	f1=f2=f3=f4=0;
	  	if (f[i-1][j]!=f[i][j]) f1++;
	  	if (f[i+1][j]!=f[i][j]) f2++;
	  	if (f[i][j-1]!=f[i][j]) f3++;
	  	if (f[i][j+1]!=f[i][j]) f4++;
	  	min1=min(a[i-1][j]+f1,a[i+1][j]+f2);
	  	min2=min(a[i][j-1]+f3,a[i][j+1]+f4);
	  	a[i][j]=min(a[i][j],min(min1,min2));
	  }else
	  {
	  	f1=f3=10000000;
	  	if (zh[i-1][j]==0) f1=a[i-1][j]+2;
	  	if (zh[i][j-1]==0) f3=a[i][j-1]+2;
	  	zh[i][j]=1;
	  	min1=min(f1,f3);
	  	if (f1<f3) f[i][j]=f[i-1][j];else
	  	f[i][j]=f[i][j-1];
	  	a[i][j]=min(a[i][j],min1);
	  }
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	  if (ff[i][j]>0)
	  {
	  	f1=f2=f3=f4=0;
	  	if (ff[i-1][j]!=ff[i][j]) f1++;
	  	if (ff[i+1][j]!=ff[i][j]) f2++;
	  	if (ff[i][j-1]!=ff[i][j]) f3++;
	  	if (ff[i][j+1]!=ff[i][j]) f4++;
	  	min1=min(a[i-1][j]+f1,a[i+1][j]+f2);
	  	min2=min(a[i][j-1]+f3,a[i][j+1]+f4);
	  	a[i][j]=min(a[i][j],min(min1,min2));
	  }else
	  {
	  	f1=f3=10000000;
	  	if (zh[i-1][j]==0) f1=a[i-1][j]+2;
	  	if (zh[i][j-1]==0) f3=a[i][j-1]+2;
	  	zh[i][j]=1;
	  	min1=min(f1,f3);
	  	if (f1<f3) ff[i][j]=ff[i-1][j];else
	  	ff[i][j]=ff[i][j-1];
	  	a[i][j]=min(a[i][j],min1);
	  }
	if (a[n][n]==10000000) printf("-1");else
	printf("%d",a[n][n]);
	return 0;
}
