#include<cstdio>
#include<cstring>
using namespace std;
int m,n;
int a[1001][1001];
bool f[1001][1001];
int dx[5]={0,0,1};
int dy[5]={0,1,0};
int best=999999999;
int dfs(int x,int y,int total,bool p)
{
	int i;
	int nx,ny;
	if(x==m&&y==m)
	 {
	 	if(total<best)
	 	best=total;
	 	return 0;
	 }
	 
	 if(total>best&&best!=999999999)
	  return 0;
	if(x>m||y>m)
	 return 0;
	for(i=1;i<=2;i++)
	 {
	  	nx=dx[i]+x;
	  	ny=dy[i]+y;
	  	if(nx>m||ny>m)
	     return 0;
	  	if(!f[nx][ny])
	  	{
	 	if(a[nx][ny]==a[x][y]&&(a[nx][ny]==1||a[nx][ny]==0))
	 	{
	 	 f[nx][ny]=1;
	 	 dfs(nx,ny,total+0,true);
	 	 f[nx][ny]=0;
	    }
	 	if(a[nx][ny]!=a[x][y]&&(a[nx][ny]==1||a[nx][ny]==0))
	 	{
	 	 f[nx][ny]=1;
	 	 dfs(nx,ny,total+1,true);
	 	 f[nx][ny]=0;
	    }
	 	if(a[nx][ny]!=1&&a[nx][ny]!=0&&p)
	 	 {
	 	   f[nx][ny]=1;
	 	   a[nx][ny]=a[x][y];
	 	   dfs(nx,ny,total+2,false);
	 	   f[nx][ny]=0;
	 	   a[nx][ny]=2;
	     }
	    if(a[nx][ny]!=1&&a[nx][ny]!=0&&!p)
	    return 0;
	    }
	 }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,2,sizeof(a));
	scanf("%d%d",&m,&n);
	int i,j;
	int x,y,z;
	for(i=1;i<=n;i++)
	 {
	 	scanf("%d%d%d",&x,&y,&z);
	 	a[x][y]=z;
	 }
	dfs(1,1,0,true);
	if(best!=999999999)
	printf("%d",best);
	 else printf("-1");
	 return 0;
}
