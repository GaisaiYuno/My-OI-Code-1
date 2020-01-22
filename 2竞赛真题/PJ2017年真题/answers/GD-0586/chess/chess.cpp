#include<stdio.h>

const int NOCOLOR=-1;
const int RED=0;
const int YELLOW=1;

int n,Colors,a[305][305],x,y,co;
bool MagicUsed[305][305],used[305][305];
int i,j,ans=2147483646;
const int dirx[5]={0,   0,0,1,-1};
const int diry[5]={0,   1,-1,0,0};
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int t;
void dfs(int x,int y,int k)
{
	if(used[x][y])
		return;
	if(x<1||y<1||x>n||y>n)
		return;
	if(x==n&&y==n)
		{
			ans=min(ans,k);
			return;
		}
	used[x][y]=true;
	for(int i=1;i<=4;i++)
		{
			if(a[x+dirx[i]][y+diry[i]]!=-1&&a[x][y]!=a[x+dirx[i]][y+diry[i]])
				dfs(x+dirx[i],y+diry[i],k+1);		
	
			if(a[x+dirx[i]][y+diry[i]]!=-1&&a[x][y]==a[x+dirx[i]][y+diry[i]])
				dfs(x+dirx[i],y+diry[i],k);
				
			if(a[x+dirx[i]][y+diry[i]]==-1&&(!MagicUsed[x][y])) 
				{
					MagicUsed[x+dirx[i]][y+diry[i]]=true;
					
					
					a[x+dirx[i]][y+diry[i]]=0;
					dfs(x+dirx[i],y+diry[i],k+2);
					
					a[x+dirx[i]][y+diry[i]]=1;
					dfs(x+dirx[i],y+diry[i],k+2);
					
					a[x+dirx[i]][y+diry[i]]=-1;
					MagicUsed[x+dirx[i]][y+diry[i]]=false;
				}
		}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&n,&Colors);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=-1;
	for(i=1;i<=Colors;i++)
		{
			scanf("%d%d%d",&x,&y,&co);
			a[x][y]=co;
		}
	dfs(1,1,0);
	if(ans==2147483646)
		printf("-1");
	else
		printf("%d",ans);
	return 0;
}
