#include<cstdio>
int m,n,f[101][101],ans,book[101][101];
int x,y,c,pd;
bool flag,ys;
void dfs(int tx,int ty,int min)
{
	int i,j;
	int next[2][2]={{1,0},{0,1}};
	if(tx==m&&ty==m)
	{
		if(ans>min)ans=min;return;
	}
	for(i=0;i<=1;i++)
	{
		if(i==1&&f[tx+next[i][0]][ty+next[i][1]]==-1)
		{
			min+=2;
			for(j=0;j<=1;j++)
			{
				if(f[tx+next[0][0]][ty+next[0][1]]==-1&&f[tx+next[1][0]][ty+next[1][1]]==-1&&f[tx+next[2][0]][ty+next[2][1]]==-1&&f[tx+next[3][0]][ty+next[3][1]]==-1)
				{
					printf("-1");
					flag=true;
					break;
				}
				book[tx][ty]=1;
				ys=f[tx][ty];
				f[tx+next[j][0]][ty+next[j][1]]=ys;
				tx+=next[j][0];
				ty+=next[j][1];
				dfs(tx,ty,min);
				book[tx][ty]=0;
			}
		}
		if(book[tx][ty]==0)
		{
			book[tx][ty]=1;
			ys=f[tx][ty];
			if(ys!=f[tx+next[i][0]][ty+next[i][1]])
			{
				min++;
			}
			tx+=next[i][0];
			ty+=next[i][1];
			dfs(tx,ty,min);
			book[tx][ty]=0;
		}
	}
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ans=-1;flag=false;
	scanf("%d%d",&m,&n);	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=-1;
		}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		f[x][y]=c;
	}
	printf("%d",ans);
}
