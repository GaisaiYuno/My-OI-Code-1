#include<cstdio>
#include<cstring>
using namespace std;
int b[4]={0,1,0,-1},c[4]={1,0,-1,0},n,m,B[1005][1005],x1,y2,num,minn=2147483647,a[1005][1005];
void dfs(int,int,int,int);
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(a,-1,sizeof(a));
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d%d",&x1,&y2,&num);
	 	a[x1][y2]=num;
	 }
	dfs(1,1,0,0);
	if (minn!=2147483647)
	 printf("%d",minn);
	else
	 printf("-1");
	return 0;
}
void dfs(int x,int y,int s,int l)
{
	if (x==n&&y==n)
	 {
	 	if (s<minn) minn=s;
	 	return ;
	 }
	for (int i=0;i<4;i++)
	 if (x+b[i]>0&&x+b[i]<=n&&y+c[i]>0&&y+c[i]<=n&&B[x+b[i]][y+c[i]]==0)
	  {
	  	B[x][y]=1;
	  	if (a[x+b[i]][y+c[i]]==-1&&l==0)
	  	 {
		   a[x+b[i]][y+c[i]]=a[x][y];
		   dfs(x+b[i],y+c[i],s+2,1);
		   a[x+b[i]][y+c[i]]=-1;
		 }
	  	if (a[x+b[i]][y+c[i]]!=a[x][y]&&a[x+b[i]][y+c[i]]!=-1&&a[x][y]!=-1)
	  	 dfs(x+b[i],y+c[i],s+1,0);
	  	if (a[x+b[i]][y+c[i]]==a[x][y]&&a[x][y]!=-1)
	  	 dfs(x+b[i],y+c[i],s,0);
	  	B[x][y]=0;
	  }
}
