#include<cstdio>
#include<cstring>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool bk;
int a[2100][2100],c[2100][2100];
int n,m,stx,sty,edx,edy,ans,min=999999999;
int mymin(int x,int y){return x<y?x:y;}
void dfs(int x,int y,int k)
{
	if(x==edx && y==edy)
	{
		min=mymin(min,ans);ans=0;
		bk=true;
	}
	else
	{
		for(int i=0;i<=3;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(a[xx][yy]>-1)
			{
				if(a[xx][yy]==c[x][y])
				{
					a[xx][yy]=-2;
					if(ans<=min)dfs(xx,yy,k+1);
					a[xx][yy]=c[xx][yy];
				}
				else
				{
					a[xx][yy]=-2;ans+=1;
					if(ans<=min)dfs(xx,yy,k+1);
					a[xx][yy]=c[xx][yy];ans-=1;
				}
			}
			else if(a[x][y]>-1)
			{
				ans+=2;
				a[xx][yy]=-2;
				if(ans<=min)dfs(xx,yy,k+1);
				a[xx][yy]=-1;
				ans-=2;
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(a,-1,sizeof(a));
	memset(c,-1,sizeof(c));
	for(int i=1;i<=m;i++)
	{
		int x,y,k;scanf("%d%d%d",&x,&y,&k);
		a[x][y]=k;c[x][y]=k;
	}
	stx=1;sty=1;edx=n;edy=n;
	a[stx][sty]=-2;
	bk=false;
	dfs(stx,sty,1);
	if(bk==false)printf("-1");
	else printf("%d\n",min);
	return 0;
}
